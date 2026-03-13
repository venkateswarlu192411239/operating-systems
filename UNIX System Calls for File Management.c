#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd;
    char data[100];

    fd=open("sample.txt",O_CREAT|O_RDWR,0777);

    printf("Enter text: ");
    scanf(" %[^\n]",data);

    write(fd,data,sizeof(data));

    lseek(fd,0,SEEK_SET);

    read(fd,data,sizeof(data));

    printf("File content: %s\n",data);

    close(fd);

    return 0;
}