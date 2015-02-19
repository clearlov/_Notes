

enum VinceAddrFamily{
    AF_INET,    // IPv4, 32bit IP + 16bit Port   
    AF_INET6,   // IPv6    
    AF_UNIX     // Unix, absolute path
};
enum VinceSockType{
    SOCK_STREAM,    // TCP  
    SOCK_DGRAM,     // UDP 
    SOCK_SEQPACKET, 
    SOCK_RAW,  
    SOCK_RDM,
};
enum VinceProtocolType{
    IPPROTO_TCP,
    IPPROTO_UDP,
    IPPROTO_SCTP,
    IPPROTO_TIPC
};



/**
 * INADDR_ANY is any IP to the server
 */
INADDR_ANY 


/******************************************************************************/ 
#include <sys/socket.h>
struct sockaddr{
    uint8_t     sa_len;
    sa_family_t sa_family;      // u_int, enumeration of VinceAddrFamily
    char        sa_data[14];    // 
};
/***********************   *********************************************/
#include <netinet/in.h>
struct sockaddr_storage{
    uint8_t     ss_len;
    sa_family_t ss_family;
}
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


int socket(int VinceAddrFamily, int VinceSockType, int VinceProtocolType)

/**
 *@return integer 0=success; -1=error;
 */
int bind(int_socket sockfd, const struct sockaddr* addr, socklen_t addr_len)

        


/**
 * backlog: max connections
 */
int listen(int_socket sockfd, int backlog)
int connect(int_socket sockfd, const struct sockaddr* addr, socklen_t addrlen)
int accept(int_socket sockfd, const struct sockaddr* addr, socklen_t addrlen)

/**
 * I/O Operations
 */
size_t read(int_socket sockfd, T * recvbuf, size_t bytes_of_recvbuf)
write(int_socket sockfd, T * sendbuf, size_t bytes_of_sendbuf)
recv() / send()
readv() / writev()
recvmsg() / sendmsg()
recvfrom() / sendto()


close(int_socket sockfd);
 