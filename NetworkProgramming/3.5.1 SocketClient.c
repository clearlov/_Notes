
int listenfd;


vDebug("socket()",
    listenfd = socket(AF_INET, SOCK_STREAM, 0)
);


/**
 * IPv4
 */
struct sockaddr_in i4; // IPv4
//bzero(&i4, sizeof(i4)); 
memset(&i4, 0, sizeof(i4)); // set to 0 using bzero()
i4.sin_family = AF_INET;
i4.sin_port = htons(SERV_LISTEN_PORT);  // consult Little Endian and Big Endian
inet_pton(AF_INET, "127.0.0.1", &i4.sin_addr); 
vDebug("connect()",
    connect(listenfd, (struct sockaddr *)&i4, sizeof(i4))
);


char sendbuf[SERV_BUF_BYTES], char recvbuf[SERV_BUF_BYTES];
struct args args;
struct results results;
if( NULL != fgets(sendbuf, SERV_BUF_BYTES, stdin) ){
    if(2 != sscanf(sendbuf, "%ld %ld", &args.arg1, &args.arg2)){
        printf("invalid input \%ld \%ld:%s", sendbuf);
        continue;
    }
    
    /**
     * First write() to elicit[ɪˈlɪsɪt] the RST
     */
    vDebug("write()",
        //write(listenfd, sendbuf, strlen(sendbuf))
        write(listenfd, &args, sizeof(args))
    );
    sleep(3);
    /**
     * Second write() to generate a SIGPIPE in server. The default action of 
     *  SIGPIPE is to teminate the process.
     */
    vDebug("write(SIGPIPD)",
        write(listenfd, sendbuf + 1, strlen(sendbuf) - 1)
    );
}


ssize_t n;
/*
if( (n = read(listenfd, recvbuf, SERV_BUF_BYTES)) > 0 ){
    recvbuf[n] = 0;     // null terminate the last char of recvbuf
    if(EOF == fputs(recvbuf, stdout)){
        printf("fputs() errno:%d(%s)\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
}
*/
if((n= read(listenfd, &results, sizeof(results))) > 0)
    printf("Serv: %ld; n=read()=%d", results.sum, n);



/**
 * IPv6
 */
struct sockaddr_in6 i6;
memset(&i6, 0, sizeof(i6)); // set to 0 using bzero()
i6.sin6_family = AF_INET6;
i6.sin6_posrt = htons(4950);
inet_pton(AF_INET6, "2001:db8:8714:3a90::12", &i6.sin6_addr);



