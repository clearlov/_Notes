#include <sys/select.h>
#include <sys/time.h>
struct timeval{
    long tv_sec;
    long tv_usec;   // microseconds
};
/**
 * @discuss fd_set data-type a bit array
 */
typedef struct{
#ifdef__USE_XOPEN
    __fd_maskfds_bits[__FD_SETSIZE/__NFDBITS];
#define__FDS_BITS(set)((set)->fds_bits)
#else
    __fd_mask__fds_bits[__FD_SETSIZE/__NFDBITS];
#define__FDS_BITS(set)((set)->__fds_bits)
#endif
} fd_set;
#define FD_SETSIZE 1024
void FD_ZERO(fd_set *fdset);
void FD_SET(int fd, fd_set *fdset);
void FD_CLR(int fd, fd_set *fdset);
void FD_ISSET(int fd, fd_set *fdset);
/**
 * @arg int maxfd_add1 the maximum no. of fds across all the sets, plus 1
 * @arg fd_set any of these args can be as a null ptr
 * @arg const struct timeval *timeout wait for any of the ready descriptors
 *  NULL ptr: wait forever
 * @return >0 on ready descriptors; 0 on timeout; -1 on error
 * @discuss when a socket is ready for reading
 *  1. received buffer > SO_RCVLOWAT  low-water; return > 0;
 *  2. connection closed (e.g. received a FIN);  return 0;
 *  3. listenfd, completed connection queue is nonzero
 *  4. socket error is pending; return -1 with errno;
 * @disuss when a socket is ready for writing
 *  1. send buffer > SO_SNDLOWAT; and connected socket or UDP;  return > 0;
 *  2. connection closed; write operation generates SIGPIPE
 *  3. socket error is pending; returns -1 with errno;
 * @discuss exception condition
 *  1. the arrival of out-of-band data for a socket
 * @disucss When an error occurs, it's marked as both readable and writable
 */
int select(int maxfd_add1, 
            fd_set *readset fd_set *writeset, fd_set *exceptset
            const struct timeval *timeout);
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            