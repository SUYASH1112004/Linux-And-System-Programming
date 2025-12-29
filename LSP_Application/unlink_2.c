#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{

    int iRet =0;

    iRet = unlink("Demo.txt");

    if(iRet==0)
    {
        printf("Unlink is successfull\n");
    }

    return 0;
}