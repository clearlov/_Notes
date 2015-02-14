void debug(const char*msg){
    printf("%s errno:%d\n", msg, errno);
}


int n, sockfd;
char buf[MAXLINE + 1];


if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    err_sys("socket() error");



/**
 * IPv6
 */
struct sockaddr_in6 i6;
//bzero(&i4, sizeof(i4)); 
memset(&i4, 0, sizeof(i4)); // set to 0 using bzero()
i6.sin6_family = AF_INET6;
i6.sin6_posrt = htons(4950);
inet_pton(AF_INET6, "2001:db8:8714:3a90::12", &i6.sin6_addr);
vDebug("connect()",
    connect(sockfd, (struct sockaddr *)&i6, sizeof(i6))
);
while( (n = read(sockfd, buf, MAXLINE)) > 0 ){
    buf[n] = 0;     /* null terminate */
    if(fputs(buf, stdout) == EOF)
        printf("fputs() errno:%d\n", errno);
}



/**
 * IPv4
 */
struct sockaddr_in i4; // IPv4
bzero(&i4, sizeof(i4)); // set to 0 using bzero()
i4.sin_family = AF_INET;
i4.sin_port = htons(3490);  // consult Little Endian and Big Endian
inet_pton(AF_INET, '10.0.0.1', &i4.sin_addr); 
bind(sockfd, (struct sockaddr*)&i4, sizeof(i4));
