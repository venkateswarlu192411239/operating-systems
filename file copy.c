#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
    int src_fd, dest_fd;
    ssize_t n;
    char buffer[BUFFER_SIZE];

    /* Open source file in read-only mode */
    src_fd = open("source.txt", O_RDONLY);
    if (src_fd < 0)
    {
        printf("Error opening source file\n");
        exit(1);
    }

    /* Open destination file in write mode, create if not exists, clear if exists */
    dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0)
    {
        printf("Error opening destination file\n");
        close(src_fd);
        exit(1);
    }

    /* Read from source and write to destination */
    while ((n = read(src_fd, buffer, BUFFER_SIZE)) > 0)
    {
        write(dest_fd, buffer, n);
    }

    if (n < 0)
    {
        printf("Error reading file\n");
    }

    /* Close both files */
    close(src_fd);
    close(dest_fd);

    printf("File copied successfully.\n");

    return 0;
}