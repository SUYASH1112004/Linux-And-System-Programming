#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
    char str[50]={'\0'};
    char m[6]={'\0'};

    printf("Enter File Name : \n");
    scanf("%s",str);

    printf("Enter the mode of File : \n");
    scanf("%s",m);

    int fd = 0;

    if(strcmp(m,"R")||strcmp(m,"r"))
    {
        fd=open(str,O_RDONLY);
    }

    else if(strcmp(m,"W")  || strcmp(m,"w"))
    {
        fd=open(str,O_WRONLY);
    }

    else if(strcmp(m,"RW") || strcmp(m,"rw"))
    {
        fd=open(str,O_RDWR);
    }

    else if(strcmp(m,"A")  || strcmp(m,"a"))
    {
        fd=open(str,O_APPEND | O_CREAT);
    }

    else
    {
        printf("Enter Valid Mode (R , W, RW, A)\n");
        return 0;
    }

    if(fd==-1)
    {
        printf("%s\n",strerror(errno));
    }
    else
    {
        printf("File Opened with fd : %d \n",fd);

    }
    return 0;
}