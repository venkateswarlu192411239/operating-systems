#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid, myPid, myPPid;

    myPid = getpid();
    printf("Before fork: Process id is %d\n", myPid);

    pid = fork();

    if (pid < 0) {
        perror("fork() failure");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("This is child process\n");
        myPid = getpid();
        myPPid = getppid();
        printf("Child PID = %d, Parent PID = %d\n", myPid, myPPid);
    } 
    else {
        // Parent process
        sleep(2);
        printf("This is parent process\n");
        myPid = getpid();
        myPPid = getppid();
        printf("Parent PID = %d and PPID = %d\n", myPid, myPPid);
        printf("Newly created child PID is %d\n", pid);
    }

    return 0;
}