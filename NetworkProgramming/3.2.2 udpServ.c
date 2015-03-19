int sockfd;

vDebug("socket()",
    sockfd = socket(AF_INET, SOCK_DGRAM, 0)
);
struct sockaddr_in i4;
memset(&i4, 0, sizeof(i4));
i4.sin_family = AF_INET;
i4.sin_port = htons(SERV_LISTEN_PORT);
i4.sin_addr.s_addr = htonl(INADDR_ANY);
vDebug("bind()",
    bind(sockfd, (const struct sockaddr*)&i4, sizeof(i4))
);
struct args args;
struct results results;
struct sockaddr_in cliaddr;
socklen_t cliaddr_len = sizeof(cliaddr);
memset(&cliaddr, 0, sizeof(cliaddr));
ssize_t n;
for(;;){
    vDebug("recvfrom()",
        n = recvfrom(sockfd, &results, sizeof(results), 0, (struct sockaddr *)&cliaddr, &cliaddr_len)
    );
    vDebug("sento()",
        sendto(sockfd, &args, sizeof(args), 0, (const struct sockaddr*)&cliaddr, cliaddr_len)
    );
}