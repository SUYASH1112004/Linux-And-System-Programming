#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char buff[400];
    int fd_arr[argc-1];
    int dfd = 0;
    int fd = 0;
    int cnt = 0;

    for(int i=1;i<argc-1;i++)
    {
        fd = open(argv[i],O_RDONLY);
        if(fd == -1)
        {
            printf("%s",strerror(errno));
            continue;
        }
        fd_arr[cnt++]=fd;
        
        
    }

    dfd=open(argv[argc-1], O_WRONLY| O_CREAT , 0777);
    if(dfd == -1)     
    {
        printf("%s",strerror(errno));
        return 1;
    }


    for(int i=0;i<cnt;i++)
    {
        int n = 0;
        while((n=read(fd_arr[i],buff,sizeof(buff)))>0)
        {
            write(dfd,buff,n);
        }
        write(dfd,"\n",1);
    }

    for(int i=0;i<cnt;i++)
    {
        close(fd_arr[i]);
    }

    close(dfd);
    printf("Data Written in Destination File \n");

    return 0;
}