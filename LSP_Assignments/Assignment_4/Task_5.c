#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
    char c;
    char sname[50];
    int fd = 0;

    printf("Enter the name of file : \n");
    scanf("%s",sname);


    fd = open(sname,O_RDONLY);
    if(fd == -1)
    {
        printf("%s",strerror(errno));
        return 1;
    }

    int size = 0;
    size=lseek(fd,0,SEEK_END);

    
    for(int i=size-1;i>=0;i--)
    {
        lseek(fd,i,SEEK_SET);
        read(fd,&c,1);
        write(1,&c,1);
    }

    printf("\n");



    return 0;
}