// sudo ./socketServ.out &   otherwise permission rejected


int listenfd;
vDebug("socket()", 
    listenfd = socket(AF_INET, SOCK_STREAM, 0)
);


struct sockaddr_in i4; // IPv4
//bzero(&i4, sizeof(i4)); 
memset(&i4, 0, sizeof(i4)); // set to 0 using bzero()
i4.sin_family = AF_INET;
i4.sin_port = htons(SERV_LISTEN_PORT);  // consult Little Endian and Big Endian
// i4.sin_addr.s_addr = htonl(INADDR_ANY);
// i4.sin_addr.s_addr = inet_addr("127.0.0.1");
inet_pton(AF_INET, "127.0.0.1", &i4.sin_addr); 
vDebug("bind()",
    -1 == bind(listenfd, (const struct sockaddr*)&i4, sizeof(i4))
);


/**
 * struct sockaddr_in serv_addr;        // if IPv4
 * struct sockaddr_in6 serv_addr;       // if IPv6
 * struct sockaddr_storage serv_addr;   // if unknown
 */
struct sockaddr_storage serv_addr;
socklen_t serv_addr_len = sizeof(serv_addr);
memset(&serv_addr, 0, serv_addr_len);
vDebug("getsockname()",
    getsockname(listenfd, (struct sockaddr *) &serv_addr, &serv_addr_len)
);
printf("family: %d\n", serv_addr.ss_family);

struct sockaddr_in serv_i4;
socklen_t serv_i4_len = sizeof(serv_i4);
memset(&serv_i4, 0, sizeof(serv_i4));
vDebug("getsockname(serv_i4)",
    getsockname(listenfd, (struct sockaddr *)&serv_i4, &serv_i4_len)
);
printf("family: %d\t", serv_i4.sin_family);
printf("port: %d\t", serv_i4.sin_port);
#define INET_ADDR_STRLEN    16
char i4_str[INET_ADDR_STRLEN];
inet_ntop(AF_INET, &serv_i4.sin_addr, i4_str, INET_ADDR_STRLEN);
printf("addr: %s\n", i4_str);


vDebug("listen()",
    listen(listenfd, SERV_LISTEN_QUEUES)
);


pid_t pid;
struct sockaddr client_addr;
int connfd;
char recvbuf[SERV_BUF_BYTES + 1], buf[SERV_BUF_BYTES + 1];

for(;;){
    vDebug("accept()",
    // connfd = accept(listenfd, (struct sockaddr *)&client_addr, &client_addr_len)
        connfd = accept(listenfd, (struct sockaddr *)NULL, NULL)
    );
    /**
     * Concurrent[kənˈkɜ:rənt] Servers
     * fork() duplicates a child process with listenfd and connfd of its own.
     */
    if( (pid = fork()) == 0){
        /**
         * back to for(;;) on errno==EINTR to restart it
         */
        if(0 ==
            vDebug("close(listenfd)",
                close(listenfd)    // child closes listening socket
            )
        ) continue;
        if( read(connfd, recvbuf, SERV_BUF_BYTES) > 0)
            snprintf(buf, SERV_BUF_BYTES, "Lef Well Says: %s", recvbuf);
        else
            snprintf(buf, SERV_BUF_BYTES, "Hello, Lef Well!");
        vDebug("write()",
            write(connfd, buf, strlen(buf))
        );
        
        /**
         * Optional: child closes connected socket
         * it's not required since the next statement calls exit(), and part of 
         *  process termination is to close all open descriptors by the kernel.
         */
        vDebug("close(connfd-child)",
            close(connfd)
        );
        exit(0);                // child terminates
    } else if(pid >0){
        /**
         * Delivered signal SIGCHLD blocks parent to call accept(), the kernel 
         *  causes the accept() to return an error of EINTR(interrupted system
         *  call). Then sigChld() executes, wait() fetches the child's PID.
         */
        signal(SIGCHLD, sigChld);
    }
    vDebug("close(connfd)",
        close(connfd)           // parent closes connected socket
    );

}



struct sockaddr_in6 i6;
i6.sin6_family = AF_INET6;
i6.sin6_posrt = htons(4950);
inet_pton(AF_INET6, "2001:db8:8714:3a90::12", &i6.sin6_addr);
bind(listenfd, (struct sockaddr*)&i6, sizeof(i6));