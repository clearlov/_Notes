/**
 * @discuss OPEN_MAX is intentionally not defined because it is no longer
 *  constant in Linux, it is runtime changeable.
 *  Use sysconf(_SC_OPEN_MAX) to query the same information.
 */
#include <unistd.h>
long sysconf(int nm);