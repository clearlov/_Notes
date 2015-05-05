#include <unistd.h>
/**
 * @note
 *  0 STDIN_FILEDNO fileno(stdin)   standard input
 *  1 STDOUT_FILENO fileno(stdout)  standard output
 *  2 STDERR_FILENO fileno(stderr)  standard error output
 *    normally stderr has no buffer, it'll output message without blocking. But
 *    sometimes stderr is same as stdout, then it has buffer.
 */
int fileno(FILE * fileptr)

/**
 * @arg const char *mode
 *  r open a file for reading
 *  w open a file for writing
 *  a open a file for writing at the end of file
 *  r+/w+ open a file for update; w+ will create the file if it does not exist
 *  a+ open a file for update at end of file
 * @example
 *  FILE *fpin = fdopen(connfd, "r");   // read from sockfd
 *    while(fgets(buf, sizeof(buf), fpin));
 *  FILE *fpout = fdopen(connfd, "w");
 *    fputs(buf, fpout);
 */
FILE * fdopen(int fd, const char *mode)


/**
 * Open a file or device
 * @arg int flags
 *    O_NONBLOCK
 *    O_APPEND
 *    O_ASYNC
 *    O_DIRECT
 *    O_NOATIME
 *    O_RDONLY
 *    O_WRONLY
 *    O_RDWR
 *    O_CREAT
 *    O_EXCL
 *    O_NOCTTY
 *    O_TRUNC
 * @return int a file descriptor
 */
int open(const char *path, int flags)

/**
 * File-descriptor control
 * @arg int cmd
 *  F_GETFD()  /  F_SETFD(int)      file descriptor flags
 *  F_GETFL()  /  F_SETFL(int)      file status flags
 * @see open()
 */
int fcntl(int fd, int cmd, ...)



#include <sys/ioctl.h> 
#include <net/if.h>
#define IFNAMSIZ      16
#define ifc_buf       ifc_ifcu.ifcu_buf;
#define ifc_req       ifc_ifcu.ifcu_req;
#define ifr_addr      ifr_ifru.ifru_addr;
#define ifr_dstaddr   ifr_ifru.ifru_dstaddr;
#define ifr_broadaddr ifr_ifru.ifru_broadaddr;
#define ifr_flags     ifr_ifru.ifru_flags;
#define ifr_metric    ifr_ifru.ifru_metric;
#define ifr_data      ifr_ifru.ifru_data;
struct ifreq{               // interface request
  char ifr_name[IFNAMSIZ];  // interface name, e.g. "lo"
  union {
    struct  sockaddr ifru_addr;
    struct  sockaddr ifru_dstaddr;
    struct  sockaddr ifru_broadaddr;
    /**
     * @var 
     *  IFF_UP
     *  IFF_BROADCAST
     *  IFF_MULTICAST
     *  IFF_LOOPBACK  loop
     *  IFF_POINTOPOINT p2p SIOCGIFDSTADDR
     */
    short   ifru_flags;
    int     ifru_metric;
    cadrr_t ifru_data;
  } ifr_ifru;
}; 
struct ifconf{
  int ifc_len;      // size of buffer, value-result
  union{
    caddr_t ifcu_buf;       // input from user -> kernel
    struct  ifreq *ifcu_req; // return from kernel -> user
  } ifc_ifcu; 
};

struct arpreq{
  struct  sockaddr arp_pa;
  struct  sockaddr arp_ha;
  int     arp_flags;
};
#define ATF_INUSE 0x01
#define ATF_COM   0x02
#define ATF_PERM  0x04
#define ATF_PUBL  0x08

/**
 * @arg int request
 *  [Socket]
 *  [File]
 *  [Interface]
 *    SIOC G/S IF CONF  get/set ifconfig (list of all interfaces), return ifconf{}
 *    SIOC G/S IF FLAGS  get/set interface flags, return ifreq{}
 *    SIOC G/S IF DSTADDR  get/set point-to-point addr. IFF_POINTOPOINT
 *    SIOC G/S IF BRDADDR  get/set broadcast addr.
 *      IPv4 only
 *    SIOC G/S IF IFMTU  get/set interface MTU, return ifreq{}
 *      Systems usually use routing sockets instead of ioctl() to access the ARP
 *        cache.
 *  [ARP]
 *    SIOC G/S/D ARP  get/set/delete ARP entry, return arpreq{}
 *  [Routing]
 *    SIOC ADD/DEL RT  add/delete route
 *  [STREAMS]
 * @return -1 on error with errno;
 *          if with errno EINVAL, the buffer specified is not large enough to
 *            hold the result
 *        >=0
 *          error on the buffer ifconf.ifc_buf is lesser than the result. 
 *            returns 0 without changing &ifconf on some OS(e.g. Berkeley-derived)
 *          success on some OS with change the ifconf.len to the result needs
 *            The real space may not be multiple to sizeof(struct ifreq)
 *            if all the ifreqs are all IPv4 (struct sockaddr), the real space
 *              is equal multiple sizeof(struct ifreq)
 *            if with IPv6 (struct sockaddr_in6), it needs more space for it
 * @note This means the only way we know that our buffer is large enough is to 
 *  issue, save the return length, issue the request again with a larger buffer,
 *  and compare the length with the saved value.
 * @example we don't know how many interfaces the server has
 *  +--------------------------------------------------------------------------+
 *  | sh$ ifconfig
 *  |   enp0s3: <UP,BROADCAST,MULTICAST>  mtu 1500
 *  |       inet 192.168.1.12  broadcast 192.168.1.255
 *  |   lo    : <UP,MULTICAST,RUNNING>  mtu 65536
 *  |       inet 127.0.0.1
 *  |   ...
 *  +--------------------------------------------------------------------------+
 *  struct ifconf if_conf;
 *  int len = 2 * sizeof(struct ifreq);   // allocate 2 ifreq{}
 *  char *buf = (char *)malloc(len);
 *  if_conf.ifc_ifcu.ifcu_len = len;
 *  if_conf.ifc_ifcu.ifcu_buf = buf;
 *  if(ioctl(sockfd, SIOCGIFCONF, &if_conf) < 0){
 *    if(errno != EINVAL)
 *      exit(0);   
 *  }
 *  free(buf);
 * @note above only suit for 2 interfaces. If there are 3 or more interface,
 *  ioctl() will return 0 (in some OS) or -1 with errno EINVAL for less room of
 *  the argument &if_conf.
 */
int ioctl(int fd, int request, ...)


/**
 * Delete a file and possibly the file it refers to
 */
int unlink(const char *path);


/**
 * +---------------------------------------------------------------------------+
 * |                    |    fd(s)    |      optional
 * |---------------------------------------------------------------------------+
 * | read() write()     | any one     |  
 * | readv() writev()   | any more    |
 * | recv() send()      | sockfd one  | flags
 * | recvfrom() sendto()| sockfd one  | flags/peer addr
 * | recvmsg() sendmsg()| sockfd more | flags/peer addr/control info
 * +---------------------------------------------------------------------------+
 */

/**
 * Attempts to read bytes_of_buf from the file associated with handle, and places the 
 *  characters read into buf. If the file is opened using O_TEXT, it removes 
 *  carriage returns and detects the end of the file.
 * @example 
 *  char remind[100]; ...; read(connfd, remind, sizeof(remind));  
 * @example
 *  struct args{long arg1; long arg2};
 *  write(connfd, &args, sizeof(args));
 *  read(connfd, &args, sizeof(args));
 * @return >0 bytes be read; 0 on End-Of-File; -1 on error
 */
int read(int file_descriptor, void * buf, size_t bytes_of_buf)
int write(int fd, void * buf, size_t bytes_of_buf)

#include <sys/uio.h>
struct iovec{
    void *iov_base;   // starting address
    size_t iov_len;   // size of transfered buffer
};
/**
 * read() one or more
 * @return ssize_t number of bytes read; -1 on error
 */
ssize_t readv(int fd, const struct iovec *iov, int iovcnt)
ssize_t writev(int fd, const struct iovec *iov, int iovcnt)


/**
 * Read chars from file_ptr and stores them into buf until (bytes_of_buf-1) or
 *  either a newline or the EOF is reached
 * @arg FILE * file_ptr stdin can be used to read from the standard input.
 * @return char * buf on success; null ptr on error
 */
char *fgets(char *buf, int bytes_of_buf, FILE * file_ptr)
/**
 * @arg FILE * file_ptr stdout can be used to output
 * @return >0 on success; EOF on error
 */
int fputs(const char *buf, FILE * file_ptr)
/**
 * @arg FILE *stream NULL on all open output streams;
 * @example
 *  fputs("", stdout);  or printf("")
 *  fflush(stdout); //  flush stdout buffers ,and print all buffer out to stdout
 */
int fflush(FILE *stream)
int fprintf(FILE *stream, const char *format, ...)

/**
 * Read formatted data from string and stores them according to args
 * @example sscanf("Hello, @LefWell 2015-10", "%s %s %ld-03", &arg1, &arg2)
 *  char arg1[] = "@LefWell"; long int arg2 = 2015
 * @return >=0 on success, args successfully filled; EOF on failure
 */
int sscanf(const char *buf, const char * format, ...)

/**
 * Write formatted data to string
 * @example sprintf(buf, "Hello, %s %ld-%d", "@LefWell", 2015, 03)
*   char buf[] = "Hello, @LefWell 2015-03"; 
 * @return >=0 on success, args successfully wrote; <0 on failure
 */
int sprintf(char *buf, const char *format, ...)

/**
 * Write formatted output to sized buf
 * @return >0 wrote bytes; 0 on buf be NULL; <0 on error  
 */
int snprintf(char *buf, size_t n, const char * format, ...)

#include <stdarg.h>
/**
 * @example vprintf("%d %d", ap);
 */
int vprintf(const char *format, va_list ap)
int vfprintf(FILE *stream, const char *format, va_list ap)
int vsprintf(char *buf, const char *format, va_list ap)
int vsnprintf(char *buf, size_t n, const char *format, va_list)