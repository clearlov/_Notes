/**
 * @disuss
 * fileno(stdin)  = 0 STDIN_FILEDNO  standard input
 * fileno(stdout) = 1 STDOUT_FILENO  standard output
 * fileno(stderr) = 2 STDERR_FILENO  standard error output
 */
int fileno(FILE *fd)

/**
 * @arg const char *mode
 *  r open a file for reading
 *  w open a file for writing
 *  a open a file for writing at the end of file
 *  r+/w+ open a file for update; w+ will create the file if it does not exist
 *  a+ open a file for update at end of file
 */
FILE * fdopen(int fd, const char *mode)