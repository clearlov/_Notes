#include <sys/select.h>
#include <sys/time.h>
/**
 * fd_set data-type a bit array
 * @disucss 0,1,2 is preserved for standard input/output/error. And the rest
 *   add one by one
 * @example
 *  fd_set allset; FD_ZERO(&allset);
 *  FD_SET(fileno(stdin), &allset); FD_SET(listenfd, &allset);
 *  client1: FD_SET(connfd, &allset);
 *  client2: FD_SET(connfd, &allset);
 *  allset = [0=>fileno(stdin), 1, 2, 3=>serv.listenfd, 4=>select1.connfd,
 *            5=>select2.connfd];
 */
typedef struct{
#ifdef __USE_XOPEN
    __fd_maskfds_bits[__FD_SETSIZE/__NFDBITS];
#define __FDS_BITS(set)((set)->fds_bits)
#else
    __fd_mask__fds_bits[__FD_SETSIZE/__NFDBITS];
#define __FDS_BITS(set)((set)->__fds_bits)
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
struct timeval{
    long tv_sec;
    long tv_usec;   // microseconds
}; 
int select(int maxfd_add1, 
            fd_set *readset, fd_set *writeset, fd_set *exceptset,
            const struct timeval *timeout);
/**
 * @arg sigmask 
 */
struct timespec{
    long tv_sec;
    long tv_nsec;   // nanoseconds
}; 
int pselect(int maxfd_add1,             
            fd_set *readset, fd_set *writeset, fd_set *exceptset,
            const struct timespec *timeout, const sigset_t *sigmask);
            
            
/**
 * +---------------------------------------------------------------------------+
 * |          |e|r|     e=events; r=revents;
 * |---------------------------------------------------------------------------|
 * |POLLIN    |Y|Y| = POLLRDNORM | POLLRDBAND
 * |POLLRDNORM|Y|Y| Normal Data can be read
 * |POLLRDBAND|Y|Y| Priority band data can be read
 * |POLLPRI   |Y|Y| High-prio., e.g. out-of-band data
 * |---------------------------------------------------------------------------|
 * |POLLOUT   |Y|Y| Normal Data can be written
 * |POLLWRNORM|Y|Y| Normal Data can be write
 * |POLLWRBAND|Y|Y| Priority band data can be written
 * |---------------------------------------------------------------------------|
 * |POLLERR   | |Y| Error has occurred
 * |POLLHUP   | |Y| Hangup has occurred
 * |POLLNVAL  | |Y| fd is not an open file
 * +---------------------------------------------------------------------------+
 * @arg int timeout
 *  INFTIM  infinite time, wait forever
 * @return >0 fds that have a nonzero revents; 0 no fd ready; -1 on error
 * @example
 *  fds[0].fd = listenfd;
 *  fds[0].events = POLLIN | POLLOUT | POLLERR; // interest in read/write/error
 *  poll(fds, 1, INFTIM);
 *  if(fds[0].revents & (POLLRDNORM | POLLERR)) // 
 */
typedef unsigned long nfds_t; 
struct pollfd{
    int fd;
    short events;       // interest
    short revents;      // occurred
};
int poll(struct pollfd * fds, nfds_t nfds, int timeout)
            
            
            
            
            
            
            
            
            
            
            
            
            