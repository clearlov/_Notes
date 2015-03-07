#include <signal.h>
/**
 * If a process terminates with children in the zombie state, the ppid of all 
 *  the zombie children is set to 1 (the init process). To clean the zombies, we
 *  establish a signal handler to catch SIGCHLD, and within the handler, we call
 *  wait().
 * @bookmark C++/1.1.3 functors - function objects
 *  Common funct and SMF are all func-ptr, they're diff with a functor.
 * @argument void (*func)(int);  func = sigChld;
 * @return void() struct sigaction.sa_handle on success; SIG_ERR on error
 *  signal(SIGCHLD, sigChld)() <=====>  sigaction.sa_handle();
 */
signal(SIGCHLD, sigChld);

void sigChld(int signo){
    pid_t pid;
    int status;
    pid = wait(&status);    // child pid terminated
}
 