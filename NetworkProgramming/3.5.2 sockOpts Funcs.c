/**
 * @arg int lvl{opt}
 *  SOL_SOCKET
 *      SO_BROADCAST
 *      SO_DEBUG TCP only
 *      SO_DONTROUTE
 *      SO_ERROR
 *      SO_KEEPALIVE
 *      SO_LINGER
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