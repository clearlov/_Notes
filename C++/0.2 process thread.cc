#include <unistd.h>
#include <sys/types.h>
#include <iostream>
using namespace std;
/**
 *
 sh$ ps al | grep forklift.out
    F UID  PID  PPID PRI NI WCHAN  STAT TTY    CMD
    0 1000 5000 4000 76  0  hrtime S+   pts/0  ./forklift.out
    1 1000 5001 5000 75  0  exit   Z+   pts/0  [forklift.out] <defunct>
    0 1000 5002 3000 76  0  pipe_w S+   pts/0  ps
*/
int main(int argc,char **argv){
    /**
     * @return pid_t 0 in child, process id of child in parent, -1 on error 
     */
    pid_t pid = fork();    // create a child process pid: 5001
    char * erode;
    if(pid>0){           // getpid()=5000; child pid=5001
        sprintf(erode, "Pid%d -> C%d\n", getpid(), pid);
    } else if(pid==0){           // getpid() = 5001, it's a child process
        sprintf(erode, "Pid%d", getpid());
    } else{
        printf("fork error");
    }
    for(;;){
        printf(erode);
        sleep(1);
    }
    return 0;
}

