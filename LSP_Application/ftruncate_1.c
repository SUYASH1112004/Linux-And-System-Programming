#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{

    int iRet = 0;
    int fd = 0;

    fd= open("Demo.txt",O_RDONLY);

    iRet= ftruncate(fd,5);

    if(iRet == 0)
    {
        printf("Truncate is successful \n");
    }
    else
    {
        printf("Their is issue in truncate");
    }

    return 0;
}