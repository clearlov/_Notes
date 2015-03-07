#include <sys/types.h>


enum signo{
    /**
     * signal child, when the child process terminates, send to its parent
     */
    SIGCHLD,
    SIG_IGN,
    SIG_DEL,
};


/**
 *
 * Simplify:
 *  #define void Sig(int);
 *  Sig * signal(int signo, Sig *func)
 *  #define void (*Sig)(int);
 *  Sig signal(int signo, Sig func);
 */
#include <signal.h>
void (*signal(int signo, void(*func)(int)))(int){
    struct sigaction act, old_act;
    act.sa_handler = func;
    sigmeptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM){
        #ifdef SA_INTERRUPT
            act.sa_flags |= SA_INTERRUPT;
        #endif
    } else {
        #ifdef SA_RESTART
            act.sa_flags |= SA_RESTART;
        #endif
    }
    if(sigaction(signo, &act, &old_act) < 0)
        return SIG_ERR;
    return old_act.sa_handler;
}



/**
 *
 */
struct sigaction {
    void (*sa_handler)(int);
    void (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
}

/**
 * Examine and change a signal action
 * @argument int signo specifies the signal and can be any valid signal except
 *  SIGKILL and SIGSTOP.
 * @argument const struct sigaction *act if non-NULL, the new action for signal 
 *  signo is installed from act
 * @argument struct sigaction *old_act if non-NULL, the previous action is saved
 *  in old_act
 */
int sigaction(int signo, 
    const struct sigaction *act, 
    struct sigaction *old_act
);



#include <sys/wait.h>
/**
 * Suspends execution until one of its children terminates
 * wait(&status_ptr) is equaivalent to waitpid(-1, &status_ptr, 0)
 * @return pid_t pid of child on success; -1 on error
 */
pid_t wait(int *status_ptr);
/**
 * @argument pid_t pid 
 *  >0  waiting for the child whose process ID is pid
 *  0   
 *  -1  
 *  <-1 
 * @argument int *status_ptr a value-result
 * @return pid_t the pid of teminated child
 *  int *status_ptr status of the terminated child
 */
pid_t waitpid(pid_t pid, int *status_ptr, int opt);
/**
 * 
 */
int waitid(idtype_t idtype, id_t id, siginfo_t *siginf, int opt);























