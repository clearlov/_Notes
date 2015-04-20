#include <sys/socket.h>
/**
 * @arg int socktype 
 *  SOCK_STREAM stream pipe which is full-duplex (both descriptors can be read
 *    and written)
 *  SOCK_DGRAM
 * @arg/return int sockfds[2] are returned as sockfds[0] sockfds[1]
 */
int socketpair(int family = AF_LOCAL, int socktype, int protocal, int sockfds[2])