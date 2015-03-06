#include <signal.h>
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
 * @param int signo specifies the signal and can be any valid signal except
 *  SIGKILL and SIGSTOP.
 * @param const struct sigaction *act if non-NULL, the new action for signal 
 *  signo is installed from act
 * @param struct sigaction *old_act if non-NULL, the previous action is saved in
 *  old_act
 */
int sigaction(int signo, 
    const struct sigaction *act, 
    struct sigaction *old_act
);