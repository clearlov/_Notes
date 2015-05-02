/**
 * shell: ifconfig
 *  enp0s3: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
 *      inet 192.168.1.12  netmask 255.255.255.0  broadcast 192.168.1.255
 *      inet6 fe80::a00:27ff:fe68:5bc6  prefixlen 64  scopeid 0x20<link>
 *      ether 08:00:27:68:5b:c6  txqueuelen 1000  (Ethernet)
 *      RX packets 86185  bytes 40641961 (38.7 MiB)
 *      RX errors 0  dropped 0  overruns 0  frame 0
 *      TX packets 74747  bytes 55261058 (52.7 MiB)
 *      TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
 *
 *  lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
 *      inet 127.0.0.1  netmask 255.0.0.0
 *      inet6 ::1  prefixlen 128  scopeid 0x10<host>
 *      loop  txqueuelen 0  (Local Loopback)
 *      RX packets 14  bytes 3612 (3.5 KiB)
 *      RX errors 0  dropped 0  overruns 0  frame 0
 *      TX packets 14  bytes 3612 (3.5 KiB)
 *      TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
 *
 */
#include <net/if.h>
#define IFS_HW_ADDRLEN 8      // hardware addrlen
struct ifs{       // interfaces
  char  name[IFNAMSIZ];      // INNAMSIZ defined in net/if.h, e.g. enp0s3
  short flags;
  short mtu;
  struct sockaddr *addr;    // inet & inet6
  struct sockaddr *brdaddr;   //broadcast addr.
  struct sockaddr *dstaddr;   // point-to-point addr.
  u_char  hwAddr[IFS_HW_ADDR_LEN];  // hardware addr., e.g. an Ethernet addr.
  u_short hwlen;      // bytes in hardware address: 0, 6, 8
  short   index;  // index of the interfaces
  struct ifs *next;
};

void free ifs(struct ifs *i){
  struct ifs *i_next;
  for(i; i != NULL; i = i_next){
    (i->addr != NULL) && free(i->addr);
    (i->brdaddr != NULL) && free(i->brdaddr);
    i_next = i->next;
    free(i);
  }
}

/**
 *  for(struct ifreq s){
 *    ioctl(sockfd, SIOCGIFFLAGS, &ifr);
 *    for(flags){
 *      ioctl(sockfd, coverted_flag, &ifre);
 *    }
 *  }
 */
struct ifs *getIfs(int addr_fam, int){
  struct ifreq *ifr, ifre;
 // struct sockaddr_in *i4;
 // struct sockaddr_in6 *i6;
  size_t sa_sz;
  struct ifs *ifi;
  switch(ifr->ifr_addr.sa_family){
    case AF_INET:
      sa_sz = sizeof(struct sockaddr_in);
      ifi->addr = calloc(1, sa_sz);
      memcpy(ifi->addr, (struct sockaddr_in *)&ifr->ifr_addr, sa_sz);
#ifdef SIOCGIFBRDADDR
      if(flags & IFF_BROADCAST){
        ioctl(sockfd, SIOCGIFBRDADDR, &ifre);
        ifi->brdaddr = calloc(1, sa_sz);
        memcpy(ifi->brdaddr, (struct sockaddr_in)&ifre.ifr_broadaddr, sa_sz);
      }
#endif
#ifdef SIOCGIFDSTADDR
      if(flags & IFF_POINTOPOINT){
        ifi->dstaddr = calloc(1, sizeof(struct dstaddr));
        ioctl(sockfd, SIOCGIFDSTADDR, &ifre);
        memcpy(ifi->dstaddr, (struct sockaddr_in *)&ifre.ifr_dstaddr, sa_sz);
      }
#endif
      break;
    case AF_INET6:
      sa_sz = sizeof(struct sockaddr_in6);
      ifi->addr = calloc(1, sa_sz);
      memcpy(ifi->addr, (struct sockaddr_in6 *)&ifr->ifr_addr, sa_sz);
#ifdef SIOGIFDSTADDR
      if(flags & IFF_POINTOPOINT){
        
      }
#endif
      break;
    default:
      break;
  }
}







 