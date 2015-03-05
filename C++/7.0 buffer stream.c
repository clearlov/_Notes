/**
 * Write formatted output to sized buf
 * @return >0 writed bytes; 0 on buf be NULL;<0 on error  
 */
int snprintf(char *buf, size_t bytes_of_buf, const char * format, ... paramters_for_format)

/**
 * Attempts to read bytes_of_buf from the file associated with handle, and places the 
 *  characters read into buf. If the file is opened using O_TEXT, it removes 
 *  carriage returns and detects the end of the file.
 * @return >0 bytes be read; 0 on End-Of-File; -1 on error
 */
int read(int file_descriptor, void * buf, size_t bytes_of_buf)
int write(int file_descriptor, void * buf, size_t bytes_of_buf)

/**
 * Read chars from file_ptr and stores them into buf until (bytes_of_buf-1) or
 *  either a newline or the EOF is reached
 * @param FILE * file_ptr stdin can be used to read from the standard input.
 * @return char * buf on success; null ptr on error
 */
char *fgets(char *buf, int bytes_of_buf, FILE * file_ptr)
/**
 * @param FILE * file_ptr stdout can be used to output
 * @return >0 on success; EOF on error
 */
int fputs(const char *buf, FILE * file_ptr)