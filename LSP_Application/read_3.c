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


    memset(buffer,'\0',SIZE_BUFFER);    //IMP Used to clean the buffer

    iRet = read(fd,buffer,10);         
    printf("%d bytes gets successfully Read \n",iRet);
    printf("Data from file : %s \n",buffer);

    close(fd);      

    return 0;
}