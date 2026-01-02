#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>


int main()
{
    char buff[400];
    char sname[100];
    char dname[100];
    int sfd = 0;
    int dfd = 0;
    int offset = 0;
    struct stat st; 

    printf("Enter Source File Name : \n");   
    scanf("%s",sname);

    printf("Enter Destination File Name : \n");   
    scanf("%s",dname);

    sfd = open(sname,O_RDONLY);
    if(sfd == -1)
    {
        printf("%s",strerror(errno));
        return 1;
    }

    stat(sname,&st);

    dfd=open(dname,O_WRONLY | O_CREAT | O_TRUNC, st.st_mode & 0777);
    if(dfd == -1)     
    {
        printf("%s",strerror(errno));
        return 1;
    }

    int n = 0;


    while((n=pread(sfd,buff,sizeof(buff),offset))>0)
    {
        pwrite(dfd,buff,n,offset);
        offset+=n;
        
    }

    printf("File Copied Successfully \n");
    close(sfd);
    close(dfd);



    return 0;
}