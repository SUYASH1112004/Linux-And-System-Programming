#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main ()
{

    int iRet = 0;

    struct stat Sobj;

    iRet=stat("Demo.txt",&Sobj);

    if(iRet==0)
    {
        printf("Stat works successfully\n");
    }
    else
    {
        printf("Their is issue in stat\n");
        return -1;
    }
    return 0;
}