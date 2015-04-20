/**
 * socketpair() And fork()
 */ 
int sockfds[2];
pid_t forkid;
socketpair(AF_LOCAL, SOCK_STREAM, 0, sockfds);

if((forkid = fork()) = 0){
  
}