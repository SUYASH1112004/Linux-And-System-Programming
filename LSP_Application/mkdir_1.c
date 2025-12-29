#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>

int main()
{

    int iRet = 0;
    int fd =0;
    
    iRet=mkdir("./Data",0777);

    if(iRet==0)
    {
        printf("Directory gets created \n");
    }

    return 0;
}