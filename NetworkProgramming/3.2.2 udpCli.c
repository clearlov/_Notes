int sockfd;

vDebug("socket()",
    sockfd = socket(AF_INET, SOCK_DGRAM, 0)
);
struct sockaddr_in i4;
socklen_t i4len = sizeof(i4);
memset(&i4, 0,i4len);
i4.sin_family = AF_INET;
i4.sin_port = htons(SERV_LISTEN_PORT);
inet_pton(AF_INET, "127.0.0.1", &i4.sin_addr);

ssize_t n;
char buf[SERV_BUF_SIZE];
struct args args;
struct results results;

while(NULL != fgets(buf, SERV_BUF_SIZE, stdin)){
    snprintf(buf, sizeof(buf), "%ld %ld", args.arg1, args.arg2);
    vDebug("sento()",
        sendto(sockfd, &args, sizeof(args), 0, (const struct sockaddr*)&i4, i4len)
    );
    vDebug("recvfrom()",
        n = recvfrom(sockfd, &results, sizeof(results), 0, NULL, NULL)
    );
    /**
     * UDP string'll not end with an EOF, so you need to add it
     * rtn_str[n] = EOF;  // or = 0 or '\0';
     */
    vDebug("fput()",
        fputs(results.sum, stdout)
    );
}