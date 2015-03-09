#include <sys/types.h>      // basic system data types
#include <sys/socket.h>     // basic socket definations
#include <sys/time.h>        // timeval{} for select()
#include <time.h>            // timespec{} for pselect()
#include <netinet/in.h>     // for sockaddr_in
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>            // for nonblocking
#include <netdb.h>
#include <signal.h>
#include <stdio.h>          // for printf
#include <stdlib.h>         // for exit
#include <string.h>         // for bzero()
#include <sys/stat.h>        // for S_xxx file mode constants
#include <sys/uio.h>         // for iovec{} and readv /writev
#include <unistd.h>
#include <sys/wait.h>
#include <sys/un.h>
#include <pthread.h>

// #define SA struct sockaddr

#define SERV_BUF_BYTES 4096 // MAXLINE, buffer size for reads and writes
#define SERV_LISTEN_QUEUES 1024 // LISTENQ 2nd arg. to listen()
#define SERV_LISTEN_PORT 9877 // any a ephemeral[ɪˈfɛmərəl] port between [5000, 49152]




int vDebug(const char*msg, int deprive){
    if(deprive<0){
        if(errno == EINTR){
            printf("errno==EINTR\n");
            return 0;
        }
        printf("%s errno:%d(%s)\n", msg, errno, strerror(errno));
        exit(EXIT_FAILURE);
        return -1;
    }
    return 1;
}