#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>

int main()
{

    int iRet =0;

    iRet = symlink("./LSP.txt","./Test/LSPl.txt");

    if(iRet==0)
    {
        printf("symlink is successfull\n");
    }
    else
    {
        printf("%s\n",strerror(errno));
    }


    return 0;
}