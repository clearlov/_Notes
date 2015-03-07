void sigChld(int signo){
    int status;
    pid_t pid = wait(&status);
}