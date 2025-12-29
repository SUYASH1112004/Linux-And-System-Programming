#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    char buffer[100]={'\0'};
    int iRet = 0;

    int fd =0 ;
    fd = open("Demo.txt",O_RDONLY);
    if(fd<0)
    {
        printf("Unable to open the file\n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File successfully open with fd : %d\n",fd);

    iRet = read(fd,buffer,10);         
    printf("%d bytes gets successfully Read \n",iRet);

    printf("Data from file : %s \n",buffer);

    close(fd);      

    return 0;
}