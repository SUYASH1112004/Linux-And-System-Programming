#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include <sys/syscall.h> 
#include<dirent.h>

int main()
{
    char dname[100];
    char fname[100];
    DIR * dp;
    struct dirent *entry;



    printf("Enter the Directory : \n");
    scanf("%s",dname);
    printf("Enter the file name : \n");
    scanf("%s",fname);

    dp=opendir(dname);

    if(dp == NULL)
    {
        printf("%s",strerror(errno));
        return 1;
    }

    while((entry=readdir(dp))!= NULL)
    {
        if((strcmp(fname,entry->d_name))==0)
        {
            printf("Absolute match path is found \n");
            return 0;
        }
    }

    printf("File not exist in given directory\n");


    return 0;
}