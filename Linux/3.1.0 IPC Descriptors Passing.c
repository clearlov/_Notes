/**
 * @arg/return int fds[0] refers to the read end; fds[1] to the write end;
 * @note Data written to the write end is buffered by the kernel until it's read
 *  +----[r0 parent 1w]-----+
 *  |                       |
 *  +----[r0 pipe 1w]-------+
 *  |                       |
 *  +----[r0 child 1w]------+
 */
int pipe(int fds)

/**
 * @arg int socktype 
 *  SOCK_STREAM stream pipe which is full-duplex (both descriptors can be read
 *    and written)
 *  SOCK_DGRAM
 * @arg/return int sockfds[2] are returned as sockfds[0] sockfds[1] both sockfds
 *  can write and read
 *  +----[rw0 parent 1rw]------+
 *  |                          |
 *  +----[rw0 socketpair 1rw]--+
 *  |                          |
 *  +----[rw0 child 1rw]-------+
 */
int socketpair(int family = AF_LOCAL, int socktype, int protocal, int sockfds[2])
/*
  +----------> waitpid() >--------->+
  |                     +----[rw0 parent 1rw]x 
  |                     |                          
  |                     +----[rw0 socketpair 1rw]--+
  |                                                |
  |                         x[rw0 child 1rw]-------+
  +<--------< exit status <--------<+
 */

int sockfds[2], status;
pid_t forkid;
socketpair(AF_LOCAL, SOCK_STREAM, 0, sockfds);

if((forkid = fork()) = 0){
  close(sockfds[0]);    // it's full-duplex ,close(sockfds[1]) is also okay
  
}

close(sockfds[1]);    // parent close one end
waidpid(forkid, &status, 0);    // waiting for the exit of child
if(WIFEXITED(status) == 0)
  