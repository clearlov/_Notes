#include <netinet/sctp.h>
/**
 * Add or remove bind a set of addresses on a socket
 * @arg int flags
 *  SCTP_BINDX_ADD_ADDR
 *  SCTP_BINDX_REM_ADDR
 */
int sctp_bindx(int sockfd, const struct sockaddr *addrs, int addrcnt, int flags)

/**
 * @arg int flags
 *  SCTP_UNORDERED un-ordered
 *  SCTP_ADDR_OVER in the one-to-many
 *  SCTP_ABORT
 *  SCTP_EOF
 */
int sctp_sendmsg(int sockfd, const void *msg, size_t msglen, 
                 const struct sockaddr *to, socklen_t tolen,
                 uint32_t ppid,
                 uint32_t flags, uint16_t stream,
                 uint32_t timetolive, uint32_t context)