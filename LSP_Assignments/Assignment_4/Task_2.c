#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>


int main()
{

    char buff[400];
    char sname[50];
    char dname[50];
    int offset = 0;
    int sfd = 0;
    int dfd = 0;
    struct stat st; 

    printf("Enter Source File Name : \n");   
    scanf("%s",sname);

    printf("Enter Destination File Name : \n");   
    scanf("%s",dname);

    printf("Enter Offset : \n");   
    scanf("%d",&offset);

    sfd=open(sname,O_RDONLY);
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

    lseek(sfd,offset,SEEK_SET);

    int n = 0;
    while((n = read(sfd,buff,sizeof(buff)))>0)
    {
        write(dfd,buff,n);
    }

    printf("File Copied Successfully \n");
    close(sfd);
    close(dfd);

    return 0;
}