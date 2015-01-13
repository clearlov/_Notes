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
    int id = fork();    // create a child process pid: 5001
    if(id>0){           // getpid()=5000; id=5001
        cout<< getpid() << " creates " << id << " then sleep..." << endl;
        sleep(20);      // current process pid: 5000 is sleeping...
    }
    if(id==0)           // getpid:5001 creates a child process
        cout << getpid() << "creates a child process" << endl;
    exit(EXIT_SUCCESS);
}

