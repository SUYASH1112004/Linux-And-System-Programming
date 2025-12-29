#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{

    int fd = 0;

    fd = open("./Test/LSPl.txt",O_RDONLY);              //Issue

    if(fd==-1)
    {
        printf("Unable to open file %s\n",strerror(errno));
        return -1;
    }

    printf("File opened with fd : %d \n",fd);

    
    
    close(fd);

    return 0;
}