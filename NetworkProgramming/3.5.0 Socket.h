#include <stdio.h>          // for printf
#include <stdlib.h>         // for exit
#include <string.h>         // for bzero()
#include <sys/types.h>      // for socket
#include <sys/socket.h>     // for socket
#include <sys/un.h>

#include <netinet/in.h>     // for sockaddr_in
#include <errno.h>
#include <pthread.h>

#define LISTENQ 1024    // 2nd arg. to listen()

#define MAXLINE 4096    // max text line length
#define BUFFSIZE 8192   // buffer size for reads and writes

#define SA struct sockaddr

void vDebug(const char*msg, int deprive){
    if(deprive)
        printf("%s errno:%d\n", msg, errno);
}