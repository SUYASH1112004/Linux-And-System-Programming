#include<stdio.h>
// #include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include <sys/syscall.h> 
#include<dirent.h>


def move(char *sname,char *dname)
{
    int sfd = 0;
    int dfd = 0;
    char buff[100];

    sfd = open(sname,O_RDONLY);
    if(sfd == -1)
    {
        printf("%s",strerror(errno));
        return 1;
    }

    struct stat st;
    stat(sname,&st);

    dfd = open(dname,O_WRONLY | O_CREAT | O_TRUNC,st.st_mode & 0777);
    if(dfd == -1)
    {
        printf("%s",strerror(errno));
        return 1;
    }
    int n = 0;

    while((n=read(sfd,buff,sizeof(buff))) > 0)
    {
        write(dfd,buff,n);
    }

    close(sfd);
    close(dfd);


    unlink(src);

}


int main()
{
    char sname[100];
    char dname[100];

    char srcpath[256];
    char despath[256];

    int cnt = 0;

    DIR *dp;
    struct dirent *entry;

    struct stat st;

    printf("Enter the Source Directory : \n");
    scanf("%s",sname);

    printf("Enter the Destination Directory : \n");
    scanf("%s",dname);


    dp = opendir(sname);

    if(dp == NULL)
    {
        printf("%s",strerror(errno));
        return 1;
    }

    while((entry=readdir(dp))!=NULL)
    {
        if((strcmp(".",entry->d_name) == 0) || (strcmp("..",entry->d_name) == 0))
        {
            continue;
        }

        snprintf(srcpath,sizeof(srcpath),"%s/%s",sname,entry->d_name);
        snprintf(despath,sizeof(despath),"%s/%s",dname,entry->d_name);

        struct stat st;
        
        stat(srcpath,&st);

        if(S_ISREG(st.st_mode))
        {
            move(srcpath,despath);
            cnt++;
        }

    }

    close(dp);
    printf("The Number of moved files : %d\n",cnt);




    return 0;
}