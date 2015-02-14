// sudo



int acceptfd, sockfd;
char buf[MAXLINE + 1];

vDebug("socket()", 
    sockfd = socket(AF_INET, SOCK_STREAM, 0)
);


 
struct sockaddr_in i4; // IPv4
//bzero(&i4, sizeof(i4)); 
memset(&i4, 0, sizeof(i4)); // set to 0 using bzero()
i4.sin_family = AF_INET;
i4.sin_port = htons(13);  // consult Little Endian and Big Endian
inet_pton(AF_INET, INADDR_ANY, &i4.sin_addr); 
vDebug("bind()",
    bind(sockfd, (const struct sockaddr*)&i4, sizeof(i4)) == -1
);

vDebug("listen()",
    listen(sockfd, LISTENQ)
);
for(;;){
    vDebug("accept()",
        acceptfd = accept(sockfd, (struct sockaddr *)NULL, NULL)
    );
    // buf = {'V', 'i', 'n' ...'\0'};
    snprintf(buf, sizeof(buf), "Vince-Well\r\n");
    vDebug("write()",
        write(acceptfd, buf, strlen(buf))
    );
    vDebug("close()",
        close(acceptfd)
    );
}



struct sockaddr_in6 i6;
i6.sin6_family = AF_INET6;
i6.sin6_posrt = htons(4950);
inet_pton(AF_INET6, "2001:db8:8714:3a90::12", &i6.sin6_addr);
bind(sockfd, (struct sockaddr*)&i6, sizeof(i6));