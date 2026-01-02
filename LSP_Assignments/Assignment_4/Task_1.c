#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>


int main(int argc,char *argv[])
{

    if(argc != 3)
    {
        printf("Enter 2 File Names as Command Line Argument .\n");
        return 1;
    }

    struct stat st;

    stat(argv[1],&st);

    char buff[400];

    int sfd = 0;
    int dfd = 0;

    sfd=open(argv[1],O_RDONLY);
    if(sfd == -1)
    {
        printf("%s",strerror(errno));
        return 1;
    }

    dfd=open(argv[2], O_WRONLY | O_CREAT | O_TRUNC  ,st.st_mode & 0777);
    if(dfd == -1)
    {
        printf("%s",strerror(errno));
        return 1;
    }


    int n = 0;

    while((n=read(sfd,buff,sizeof(buff)))>0)
    {
        write(dfd,buff,n);
    }

    printf("Content Copied From Source to Destination \n");
    close(sfd);
    close(dfd);


    return 0;
}