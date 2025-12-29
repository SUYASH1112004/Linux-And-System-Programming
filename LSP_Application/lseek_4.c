#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define SIZE_BUFFER 100

int main()
{
    char buffer[SIZE_BUFFER];
    int iRet = 0;

    memset(buffer,'\0',SIZE_BUFFER);    
    // Memset is used to initialize the array by \0

    int fd =0 ;
    fd = open("Hole.txt",O_WRONLY | O_CREAT);
    if(fd<0)
    {
        printf("Unable to open the file\n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File successfully open with fd : %d\n",fd);

    iRet = lseek(fd,4100,SEEK_SET);

    printf("Current offset is : %d \n",iRet);

    iRet=write(fd,"END",3);

    printf("%d bytes gets return successsfully \n",iRet);
    
    close(fd);

    return 0;
}