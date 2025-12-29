#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd = 0;
    fd = open("Marvellous.txt",O_RDONLY);

    printf("Value of fd is : %d \n",fd);

    if(errno!=0)
    {
       switch(errno)
       {
            case ENOENT:
                printf("Their is no such file create the file and open \n");
                break;
       
            case EACCES:
                printf("Unable to access as their is no permission \n");
                break;
            default:
                printf("%s",strerror(errno));
        }
    }
    
    return 0;
}