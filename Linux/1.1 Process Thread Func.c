#include <unistd.h>
#include <syslog.h>
/**
 * Create a session and set it to the process group ID
 * @return pid_t the new session ID on success; -1 with errno on error
 * ���ڴ����ػ����̵ĵ�һ��������fork�����������ӽ��̣��ٽ��������˳��������ڵ�����fork����ʱ���ӽ���ȫ�̿����˸����̵ĻỰ�ڡ������顢�����ն˵ȣ���Ȼ�������˳��ˣ����Ự�ڡ������顢�����ն˵Ȳ�û�иı䣬��ˣ��⻹�������������ϵĶ�����������setsid�����ܹ�ʹ������ȫ�����������Ӷ������������̵Ŀ��ơ�
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
