#include <unistd.h>
#include <syslog.h>
/**
 * Create a session and set it to the process group ID
 * @return pid_t the new session ID on success; -1 with errno on error
 * 由于创建守护进程的第一步调用了fork函数来创建子进程，再将父进程退出。由于在调用了fork函数时，子进程全盘拷贝了父进程的会话期、进程组、控制终端等，虽然父进程退出了，但会话期、进程组、控制终端等并没有改变，因此，这还不是真正意义上的独立开来，而setsid函数能够使进程完全独立出来，从而摆脱其他进程的控制。
 */
pid_t setsid()

/**
 * Since a daemon does not have a controlling terminal, it cannot just fprintf
 *  to stderr. Using syslog() instead
 * @arg prio combines a level and a facility
 *  level
 *    0 LOG_EMEG
 *    1 LOG_ALERT
 *    2 LOG_CRIT
 *    3 LOG_ERR
 *    4 LOG_WARNING
 *    5 LOG_NOTICE
 *    6 LOG_INFO
 *    7 LOG_DEBUG
 *  facility
 *    LOG_AUTH security/authorization messages
 *    LOG_AUTHPRIV security/authorization messages(private)
 *    LOG_CRON cron daemon
 *    LOG_DAEMON
 *    LOG_FTP
 *    LOG_KERN
 *    LOG_LOCAL0
 *    ..
 *    LOG_LOCAL7
 *    LOG_LPR line printer system
 *    LOG_MAIL
 *    LOG_NEWS
 *    LOG_SYSLOG
 *    LOG_USER
 *    LOG_UUCP 
 * @example syslog(LOG_INFO | LOG_LOCAL2, "re(%s, %s):%m", file1, file2); 
 */
void syslog(int prio, const char *msg, ...)
/**
 * it can be perpended or appended to syslog()
 * @arg int opts
 *  LOG_CONS
 *  LOG_NDELAY
 *  LOG_PERROR
 *  LOG_PID
 */
void openlog(const char *ident, int opts, int facility)
void close();
