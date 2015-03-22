#include <netinet/sctp.h>
/**
 * Add or remove bind a set of addresses on a socket
 * @arg int flags
 *  SCTP_BINDX_ADD_ADDR
 *  SCTP_BINDX_REM_ADDR
 */
int sctp_bindx(int sockfd, const struct sockaddr *addrs, int addrcnt, int flags)