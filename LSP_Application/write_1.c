#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    char buffer[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int iRet = 0;

    int fd =0 ;
    fd = open("Demo.txt",O_WRONLY);
    if(fd<0)
    {
        printf("Unable to open the file\n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File successfully open with fd : %d\n",fd);

    iRet = write(fd,buffer,10);
    printf("%d bytes gets successfully written \n",iRet);

    close(fd);      //stat demo.txt

    return 0;
}