#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{

    char name[30]={'\0'};
    char per[6]={'\0'};

    printf("Enter the file name :\n");
    scanf("%s",name);

    printf("Enter the mode of file (R,W,X) :\n");
    scanf("%s",per);

    int val = 0;

    if(strcmp("R",per)==0)
    {
        val=access(name,R_OK);
    }
    else if(strcmp("W",per)==0)
    {
        val=access(name,W_OK);
    }
    else if(strcmp("X",per)==0)
    {
        val=access(name,X_OK);
    }
    
    
    if( val == -1)
    {
        printf("Not accessible : %s\n",strerror(errno));
    }
    else if(val == 0)
    {
        printf("Accessible \n");
    }
    else
    {
        printf("Enter a valid mode \n");
    }


    return 0;
}