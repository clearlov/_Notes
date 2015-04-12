#include <netdb.h>
struct hostent{   // host entry
  char *h_name;       // canonical[kə'nɒnɪkl] name of host \0
  char **h_aliases;   // 
  int h_addrtype;     // e.g. AF_INET
  int h_length;       // e.g. sizeof(sockaddr_in)
  char **h_addr_list; // 
  
};

struct hostent *gethostbyname(const char *hostnm)
struct hostent *gethostbyaddr(const char *addr, socklen_t len, int family)


struct servent{
  char *s_name;
  char **s_aliases;
  int s_port;
  char *s_proto;
};
/**
 * @note sh$ cat /etc/services
 *  [serv_nm] [port]/[proto_nm]
 *  domain      53/tcp
 *  domain      53/udp
 *  domaintime  9909/tcp
 *  domaintime  9909/udp
 *  http        80/tcp
 *  http        80/udp
 *  http        80/sctp
 *  https       443/tcp
 *  https       443/udp
 *  https       443/sctp
 *  netstat     15/tcp
 *  ssh         22/tcp
 *  ssh         22/udp
 *  ssh         22/sctp
 */
struct servent *getservbyname(const char *serv_nm, const char *proto_nm)
/**
 * @arg int port htons(port)
 */
struct servent *getservbyport(int port, const char *proto_nm)

struct addrinfo{
  /**
   * @var 
   *  AI_PASSIVE
   *  AI_CANONNAME
   *  AI_NUMERICHOST
   *  AI_V4MAPPED
   *  AI_ALL
   *  AI_ADDRCONFIG
   */
  int ai_flags;
  int ai_family;          // AF_
  int ai_socktype;        // SOCK_
  int ai_protocol;        // 0 or IPPROTO_
  socklen_t ai_addrlen;
  char *ai_cononname;
  struct sockaddr *ai_addr;
  struct addrinfo *ai_next;
};
int getaddrinfo(const char *host_nm, const char *service,
                const struct addrinfo *hints, struct addrinfo **result)