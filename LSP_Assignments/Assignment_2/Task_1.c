#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>

#define Buff_Size 1024

int main()
{

    char name[20];
    printf("Enter the name of file : \n");
    scanf("%s",name);

    int fd = 0;

    fd=open(name,O_RDONLY);
    if(fd==-1)
    {
        printf("File not opened , %s\n",strerror(errno));
        return 1;
    }
    
    char buff[Buff_Size] = {'\0'};

    int n = 0;
    int size_read = 0;
    
    while((n=read(fd,buff,Buff_Size))>0)
    {
        write(1,buff,n);
        size_read=n;
    }
    printf("\n");
    
    close(fd);
    printf("Total bytes read : %d\n",size_read);

    return 0;
}