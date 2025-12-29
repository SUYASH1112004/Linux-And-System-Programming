#include<stdio.h>
#include<unistd.h>


int main()
{

    int iRet = 0;

    iRet=truncate("Demo.txt",10);

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