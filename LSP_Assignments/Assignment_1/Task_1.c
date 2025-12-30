#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{

    int fd = 0;
    char str[50];

    printf("Enter File Name : \n");
    scanf("%s",str);

    fd = open(str,O_RDWR);

    if(fd == -1)
    {
        printf("Error Occured : %s \n",strerror(errno));
    }
    else
    {
        printf("File opened Successfully with fd : %d \n",fd);
    }

    return 0;
}