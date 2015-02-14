/**
 * Three-Way Handshake in TCP Connections:
    Synchronize   Acknowledge
    ---------- HOST A ---------------|---------------- HOST B ------------------
    socket() --> connect()  --> [SYN J]
    [SYN_SEND, blocks connect()]     |
                                     |                listen <== bind <== socket
                                    [SYN K, ACK J+1] <== accept() <==
                                     |               [SYN_RECV, blocks accept()]
    connect()             --> [ACK K+1]
                                     |                 accept()
                                     |
                                     |
                                     |                                     
    ---------- HOST A ---------------|---------------- HOST B ------------------
 * Four-Way Handshake in TCP Close:
    ---------- HOST A ---------------|---------------- HOST B ------------------
                                     |                                 
                            -->    [FIN M]
    [Wait for ACK and FIN from B]    |
                                  [FIN N, ACK M+1]                   <== close()
                            --> [ACK N+1]
                                     |                 
                                     |
                                     |
                                     |                                     
    ---------- HOST A ---------------|---------------- HOST B ------------------   
                            
                                                                    <== close()
    
    --> close --> shutdown
    
 */

enum VinceAFamily{
    AF_INET,    // IPv4, 32bit IP + 16bit Port   
    AF_INET6,   // IPv6    
    AF_UNIX     // Unix, absolute path
};
enum VinceType{
    SOCK_STREAM,    // TCP  
    SOCK_DGRAM,     // UDP 
    SOCK_SEQPACKET, 
    SOCK_RAW,  
    SOCK_RDM,
};
enum VinceProtocol{
    IPPROTO_TCP,
    IPPROTO_UDP,
    IPPROTO_SCTP,
    IPPROTO_TIPC
};



int socket(int VinceAFamily, int VinceType, int VinceProtocol)

/**
 *@return integer 0=success; -1=error;
 */
int bind(int_socket sockfd, const struct sockaddr* addr, socklen_t addr_len)
/**
 * Presentation to numeric: Convert IP addr. from 'Dotted Decimal Notation' to Binary, 
   and assign to 'in_addr' or 'in6_addr' struct
 * dst_strct: 'in_addr' or 'in6_addr' struct , depended on VinceAFamily
 */
#include <arpa/inet.h>
int inet_pton(int VinceAFamily, const char *ip_str, void *dst_struct)
        

/******************************************************************************/ 
struct sockaddr{
    unsigned short sa_family;   // equal VinceAFamily
    char sa_data[14];           //
};
/*********************** IPv4 *************************************************/
struct sockaddr_in {
    sa_family_t sin_family;     // AF_INET
    in_port_t sin_port;         // 16bit
    struct in_addr sin_addr;    // 32bit
};
struct in_addr {
    uint32_t s_addr;
};
/*********************** IPv6 *************************************************/
struct sockaddr_in6 {
    sa_family_t     sin6_family;    // AF_INET6
    in_port_t       sin6_port;      // 16bit
    uint32_t        sin6_flowinfo;  // 32bit
    struct in6_addr sin6_addr;      // 1bit
    uint32_t        sin6_scope_id;  // 32bit
};
struct in6_addr {
    unsigned char   s6_addr[16];
};
//Unix
struct sockaddr_un {
    sa_family_t sun_familty;    // AF_UNIX
    char sun_path[108]; // path
};
/*******************************************************************************/

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
 