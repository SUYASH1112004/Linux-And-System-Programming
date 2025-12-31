#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

int main()
{

    char name[20]={'\0'};
    char data[100]={'\0'};
    int fd = 0;
    int icnt = 0;

    printf("Enter the name of file : \n");
    scanf("%s",name);
    getchar();


    printf("Enter the string to append in file : \n");
    icnt=read(0,data,sizeof(data));
    
    fd = open(name,O_APPEND | O_WRONLY);

    if(fd == -1)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }

    int val = 0;
    val = write(fd,data,icnt);

    if(val == -1)
    {
        printf("%s",strerror(errno));
    }

    printf("Number of bytes written %d \n",val);

    close(fd);
    return 0;

}