#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>


int main()
{

    char name[20]={'\0'};
    int n = 0;
    

    printf("Enter the name of file : \n");
    scanf("%s",name);

    printf("Enter the number of bytes to read : \n");
    scanf("%d",&n);


    char *buff = (char*)malloc(n+1); 

    int fd = 0;

    fd = open(name,O_RDONLY);

    if(fd == -1)
    {
        printf("File not opened : %s",strerror(errno));
        return 1;
    }

    int r = 0;

    
    r= read(fd,buff,n);


    buff[r]='\0';

    printf("Data from file : %s\n",buff);


    close(fd);
    free(buff);

    return 0;
}