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
    bind(listenfd, (const struct sockaddr*)&i4, sizeof(i4))
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
printf("family: %d  ", serv_addr.ss_family);

struct sockaddr_in serv_i4;
socklen_t serv_i4_len = sizeof(serv_i4);
memset(&serv_i4, 0, sizeof(serv_i4));
vDebug("getsockname(serv_i4)",
    getsockname(listenfd, (struct sockaddr *)&serv_i4, &serv_i4_len)
);
//printf("family: %d  ", serv_i4.sin_family);
printf("port: %d  ", serv_i4.sin_port);
if(!serv_i4.sin_port > 0){
    printf("port error");
    exit(0);
}
#define INET_ADDR_STRLEN    16
char i4_str[INET_ADDR_STRLEN];
inet_ntop(AF_INET, &serv_i4.sin_addr, i4_str, INET_ADDR_STRLEN);
printf("addr: %s\n", i4_str);


vDebug("listen()",
    listen(listenfd, SERV_LISTEN_QUEUES)
);

ssize_t n;
pid_t pid;
struct sockaddr cli_addr;
socklen_t cli_addr_len;
int connfd;
char recvbuf[SERV_BUF_SIZE + 1], buf[SERV_BUF_SIZE + 1];
struct args args;
struct results results;
memset(&results, 0, sizeof(results));
/**
 * Concurrent[kənˈkɜ:rənt] Servers for multiple clients
 * 
 */
fd_set rset, allset;
int i, nready, maxfd, maxi, tempfd, clis[FD_SETSIZE];
maxfd = listenfd;
maxi=-1;
// client available
#define CLI_AVL -1
for(i=0; i<FD_SETSIZE; ++i)
    clis[i] = CLI_AVL;            // -1 indicates avaliable entry
FD_ZERO(&allset);
FD_SET(listenfd, &allset);


for(;;){
    rset = allset;
    // printf("listenfd:%d; maxfd:%d\n", listenfd, maxfd);
    vDebug("select()",
        nready = select(maxfd+1, &rset, NULL, NULL, NULL)
    );
    /**
     * new client connection
     */
    if(FD_ISSET(listenfd, &rset)){
        cli_addr_len = sizeof(cli_addr_len);    // ipv4 or ipv6 for each
        if(0 ==
            vDebug("accpet()",
                connfd = accpet(listenfd, &cli_addr, &cli_addr_len)
            )
        ) continue;
        // set connfd into available clis[]
        for(i=0; i< FD_SETSIZE; ++i){
            if(clis[i] == CLI_AVL){
                clis[i] = connfd;
                break;
            }
        }
        //printf("client[%d] on woking...\n", %i)
        FD_SET(connfd, &allset);
        if(connfd > maxfd)  maxfd = connfd;
        if(i>maxi) maxi = i;
        if(--nready <=0) continue;
    }
    for(i=0;i<=maxi;++i){
        if((tempfd = client[i]) < 0)
            continue;
        if(FD_ISSET(tempfd, &rset)){
            if( (n=read(tempfd, &args, sizeof(args))) == 0){
                vDebug("Serv close()",
                    close(tempfd)
                );
                FD_CLR(tempfd);
                clis[i] = -1;
            } else{
                results.sum = args.arg1 + args.arg2;
                printf("Client(%d): %ld %ld", tempfd, args.arg1, args.arg2);
                printf("Return:%ld\n", results.sum);
                vDebug("Serv write()",
                    write(connfd, &results, sizeof(results))
                );
            }
            if(--nready <=0)
                break;
        }
    }
}