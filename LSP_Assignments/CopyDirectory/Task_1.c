#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>



int main()
{
    char sname[50];
    char dname[50];

    char buff[100];

    struct stat st;

    

    int sfd = 0;
    int dfd = 0;
    

    printf("Enter source file name : \n");
    scanf("%s",sname);

    printf("Enter destination file name : \n");
    scanf("%s",dname);

    
    dfd = open(dname,O_CREAT | O_WRONLY | O_TRUNC ,0644);

    if(dfd == -1)
    {
        printf("%s",strerror(errno));
        return 1;
    }

    sfd = open(sname,O_RDONLY);
    if(sfd == -1)
    {
        printf("%s",strerror(errno));
        return 1;
    }

    stat(sname,&st);



    int n = 0;

    while((n = read(sfd,buff,sizeof(buff))) > 0 )
    {
        write(dfd,buff,n);
    }

    if(n == -1)
    {
        printf("%s",strerror(errno));
        return 1;
    }

    chmod(dname,st.st_mode & 0777);


    printf("Data written in Destination file \n");
    close(dfd);
    close(sfd);
    



    return 0;
}