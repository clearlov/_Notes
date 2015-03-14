/**
 * Attempts to read bytes_of_buf from the file associated with handle, and places the 
 *  characters read into buf. If the file is opened using O_TEXT, it removes 
 *  carriage returns and detects the end of the file.
 * @example 
 *  char remind[100]; ...; read(connfd, remind, sizeof(remind));  
 * @example
 *  struct args{long arg1; long arg2};
 *  write(connfd, &args, sizeof(args));
 *  read(connfd, &args, sizeof(args));
 * @return >0 bytes be read; 0 on End-Of-File; -1 on error
 */
int read(int file_descriptor, void * buf, size_t bytes_of_buf)
/**
 * @discuss errno:9(Bad file descriptor)
 *  
 */
int write(int file_descriptor, void * buf, size_t bytes_of_buf)

/**
 * Read chars from file_ptr and stores them into buf until (bytes_of_buf-1) or
 *  either a newline or the EOF is reached
 * @arg FILE * file_ptr stdin can be used to read from the standard input.
 * @return char * buf on success; null ptr on error
 */
char *fgets(char *buf, int bytes_of_buf, FILE * file_ptr)
/**
 * @arg FILE * file_ptr stdout can be used to output
 * @return >0 on success; EOF on error
 */
int fputs(const char *buf, FILE * file_ptr)


/**
 * Read formatted data from string and stores them according to args
 * @example sscanf("Hello, @LefWell 2015-10", "%*s %s %ld-03", &arg1, &arg2)
 *  char arg1[] = "@LefWell"; long int arg2 = 2015
 * @return >=0 on success, args successfully filled; EOF on failure
 */
int sscanf(const char * buf, const char * format, ...)

/**
 * Write formatted data to string
 * @example sprintf(buf, "Hello, %s %ld-%d", "@LefWell", 2015, 03)
*   char buf[] = "Hello, @LefWell 2015-03"; 
 * @return >=0 on success, args successfully wrote; <0 on failure
 */
int sprintf(char * buf, const char * format, ...)

/**
 * Write formatted output to sized buf
 * @return >0 wrote bytes; 0 on buf be NULL; <0 on error  
 */
int snprintf(char *buf, size_t bytes_of_buf, const char * format, ...)