

enum LefAddrFamily{
    AF_INET,    // IPv4, 32bit IP + 16bit Port   
    AF_INET6,   // IPv6  
    AF_LOCAL,   // AF_UNIX(the historial Unix name) absolute path
    AF_ROUTE,   // Routing sockets
    AF_KEY      // Key socket
};
enum LefSockType{
    SOCK_STREAM,    // stream TCP  
    SOCK_DGRAM,     // datagram UDP 
    SOCK_SEQPACKET, // sequenced packet
    SOCK_RAW,       // raw
};
enum LefProtocolType{
    IPPROTO_TCP,
    IPPROTO_UDP,
    IPPROTO_SCTP,
};



/**
 * INADDR_ANY is a wildcard IP addr. to the server
 */
INADDR_ANY 


/******************************************************************************/ 
#include <sys/socket.h>
struct sockaddr{
    uint8_t     sa_len;
    sa_family_t sa_family;      // u_int, enumeration of LefAddrFamily
    char        sa_data[14];    // 
};
/*********************** IPv4 *************************************************/
#include <netinet/in.h>
struct in_addr {
    in_addr_t s_addr;               // uint32_t
};
struct sockaddr_in{
    uint8_t         sin_len;
    sa_family_t     sin_family;     // u_int, AF_INET
    in_port_t       sin_port;       // uint16_t 
    struct in_addr  sin_addr;       // uint32_t
    char            sin_zero[8];    // unused
};
/*********************** IPv6 *************************************************/
struct in6_addr{
    uint8_t   s6_addr[16];          // network byte ordered 128-bit IPv6 addr.
};
struct sockaddr_in6{
    uint8_t         sin6_len;       // length of this struct (28)
    sa_family_t     sin6_family;    // AF_INET6
    in_port_t       sin6_port;      // 16bit
    uint32_t        sin6_flowinfo;  // 32bit
    struct in6_addr sin6_addr;      // 128bit
    uint32_t        sin6_scope_id;  // 32bit
};

/*********************** Unix *************************************************/
//Unix
struct sockaddr_un{
    sa_family_t sun_familty;    // AF_UNIX
    char sun_path[108]; // path
};

/******************************************************************************/
/**
 * Since we don't know whether the socket addr. is IPv4(sockaddr_in) or 
 *  IPv6(sockaddr_in6), we use sockaddr_storage
 */
#include <netinet/in.h>
struct sockaddr_storage{
    uint8_t     ss_len;
    sa_family_t ss_family;
} 
/******************************************************************************/





/**
 * @return int file descriptor
 */

int socket(int LefAddrFamily, int LefSockType, int LefProtocolType)

/**
 * assign a local protocol address to a socket.
 * @return integer 0=success; -1=error;
 */
int bind(int listenfd, const struct sockaddr* addr, socklen_t addr_len)

        


/**
 * be called by TCP server.
 * status change: CLOSED --> LISTEN(passive open)
 * max_listen_queues = incomplete_connection_queues + completed_connection_queues
 *      received: SYN j, MSS=536 ..
 *  incomplete_connection_queues (SYN_RCVD state):  have a time out of 75s
 *      send:    SYN k, ACK j+1, MSS=1460 ...
 *      RTT: about 187ms
 *      received: ACK k+1 ...
 *  completed_connection_queues (ESTABLISHED state): 3-way handshake completed
 * When the process calls accept(), the first entry on the completed queue is 
 *  returned to the process, or if the queue is empty, the process is put to
 *  sleep until an entry is placed onto the completed queue.
 * @arg int max_listen_queues 
 *  It is multiplied by 1.5 in MacOS and added 3 in Linux.
 *  e.g. listen(listenfd, 2048) --> 3072 queues in MacOS and 2051 queues in Linux
 *  Provide enough number of queues for SYN flooding.
 * If the queues are full when a client SYN arrives, TCP ignores the arriving SYN;
 *  it does not send an RST. The client TCP'll retransmit its SYN, hopefully 
 *  finding room on the queue in the near future.
 * If the server responded with an RST, the client's connect() would return an
 *  error.
 */
int listen(int listenfd, int max_listen_queues)

/**
 * be used by a TCP client to establish a connection with a TCP server
 * status change: SYN_SENT(active open)
 */
int connect(int listenfd, const struct sockaddr* serv_addr, socklen_t addrlen)

/**
 * When a process is blocked in "slow system call"(will ever return, like 
 *  for(;;) and read()) and the process catches a signal and the signal handler
 *  returns, the system call can return EINTR(interrupted system call).
 * @arg client_addr is used to return the protocol addr. of the connected peer
 *  process (the client).
 * @arg addrlen is a value-result arg.
 *  value: sizeof(client_addr)
 *  result: actual number of bytes stored by the kernel in the socket addr. structure
 * @return integer connected socket file descriptor 
 *  (for which the TCP three-way handshake completeds)
 */
int accept(int listenfd, struct sockaddr* client_addr, socklen_t addrlen)


int close(int listenfd)



/**
 * @arg int flags 
 *  MSG_OOB out-of-band data
 *  MSG_PEEK
 *  MSG_WAITALL
 */
ssize_t recv(int listenfd, void *buf, size_t len, int flags)
/**
 * Receive a msg. from a connection-mode or connectionless-mode socket. It is 
 *  normally used with connectionless-mode sockets because it permits the 
 *  application to retrieve the source address of received data.
 * @return >=0 on success, bytes received; -1 on error
 */
ssize_t recvfrom(int listenfd, void *buf, size_t len, int flags,
                 struct sockaddr *serv_addr, socklen_t addrlen)
                 
                 
send()
readv() / writev()
recvmsg() / sendmsg()


sendto()


/**
 * @arg socklen_t * addrlen  is quite different with socklen addrlen
 */

int getsockname(int listenfd, struct sockaddr *localaddr, socklen_t * addrlen)
int getpeername(int listenfd, struct sockaddr *peeraddr, socklen_t * addrlen)


 