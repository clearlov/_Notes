/**
 * @arg int lvl{opt}
 *  SOL_SOCKET
 *      SO_BROADCAST
 *      SO_DEBUG TCP only
 *      SO_DONTROUTE
 *      SO_ERROR
 *      SO_KEEPALIVE if no data exchanged for 2 hours, TCP automatically sends a
 *       "keep-alive probe"(a TCP segment) to the peer, the peer must respond
 *       1 If the peer responds with an ACK, but is not notified. Resend probe
 *       2 If the peer responds with an RST, socket is closed with ECONNNRESET
 *       3 If no response, TCP sends 8 more probes, 75 seconds apart. TCP'll
 *          give up if no response within 11 minutes and 15 seconds, the socket
 *          is closed with ETIMEDOUT
 *      SO_LINGER see struct linger{} below
 *       1 If l_onoff=0, SO_LINGER turns off. close() returns immediately
 *       2 If l_linger=0, TCP discards any data still remaining in the socket
 *          send buffer and sends an RST to the peer, not the normal 4-packet.
 *       3 If l_onoff is on, l_linger>0, kernel lingers when socket is closed.
 *          If there's any data still remaining in the socket send buffer, the
 *          process is put to sleep until either:
 *            (1) all the data is sent and acknowledged by the peer TCP;
 *            (2) the linger time expires, close() returns EWOULDBLOCK
 *       +---------------------------------|-----------------------------------+
 *       |  Default Operation of close(): returns immediately
 *       +---------------------------------|-----------------------------------+
 *       | write()                      -->          (SRB:socket receive buffer)
 *       |                                       busy server, data queued in SRB 
 *       | close()               --FIN M-->   
 *       | close() returns immediately    
 *       |                                            read queued data, then FIN
 *       |                                  <--ACK of data & FIN M--
 *       |                                  <--FIN N--                   close()
 *       |                     --ACK N+1-->
 *       +---------------------------------|-----------------------------------+
 *         The client's close() can return before the server reads the remaining
 *          data in its socket receive buffer. The server may crash before 
 *          'read queued data, then FIN', and the client will never know.
 *       +---------------------------------|-----------------------------------+
 *       |  close() with SO_LINGER, l_onoff!=0; l_linger>0
 *       +---------------------------------|-----------------------------------+
 *       |     write()                  -->          (SRB:socket receive buffer)
 *       |                                       busy server, data queued in SRB 
 *       |     close()           --FIN M-->
 *       |---------------------------------+
 *       |      close() returns in         |          read queued data, then FIN
 *       |       l_linger seconds          |<--ACK of data & FIN M--
 *       |---------------------------------+
 *       |                                  <--FIN N--                   close()
 *       |                     --ACK N+1-->
 *       +---------------------------------|-----------------------------------+
 *         If time l_linger is smaller than 'ACK M+1' despondence, It'll be same
 *          as above. And close() returns -1 with errno EWOULDBLOCK. Only if 
 *          'ACK M+1' responds in the period l_linger seconds, the client'll know
 *          that the server has read its data.
 *       +---------------------------------|-----------------------------------+
 *       |  shutdown(listenfd, SHUT_WR) : peer has received data
 *       +---------------------------------|-----------------------------------+
 *       | write()                      -->          (SRB:socket receive buffer)
 *       |                                       busy server, data queued in SRB 
 *       | shutdown()            --FIN M-->
 *       |                                  <--ACK of data & FIN M--
 *       |                                            read queued data, then FIN
 *       |                                  <--FIN N--                   close()
 *       | read() returns 0
 *       |                     --ACK N+1-->
 *       +---------------------------------|-----------------------------------+
 *      SO_OOBINLINE
 *      SO_RCVBUF
 *      SO_RCVLOWAT
 *      SO_SNDBUF
 *      SO_SNDLOWAT
 *  IPPROTO_IP
 *  IPPROTO_ICMPV6
 *  IPPROTO_IPV6
 *  IPPROTO_IP
 *  IPPROTO_TCP
 *      TCP_MAXSEG
 *      TCP_NODELAY
 *  IPPROTO_SCTP
 * @arg int opt_nm
 * @arg void *opt_val
 * @return int 0 on success; -1 on error with errno
 * @example
 *  socklen_t len;
 *  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
 *  getsockopt(sockfd, IPPROTO_TCP, &opt_val, &len);
 */
struct linger{
    int l_onoff;    // 0=off, nonzero=on
    int l_linger;   // linger time, POSIX specifies units as seconds
};
union opt_val{
    int i_val; 
    long l_val; 
    struct linger linger_val; 
    struct timeval timeval_val
} opt_val;
int getsockopt(int sockfd, int lvl, int opt_nm, void *opt_val, socklen_t *optlen)
int setsockopt(int sockfd, int lvl, int opt_nm, const void *opt_val, socklen_t optlen)