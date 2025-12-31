#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<sys/syscall.h>
#include<unistd.h>

int main()
{

    DIR *dp;
    struct dirent *entry;
    char name[100];

    printf("Enter the name of directory \n");
    scanf("%s",name);

    dp=opendir(name);

    if(dp == NULL)
    {
        printf("%s",strerror(errno));
        return 1;
    }


    while((entry = readdir(dp))!= NULL)
    {
        if((strcmp(".",entry->d_name))==0)
        {
            continue;
        }
        if((strcmp("..",entry->d_name))==0)
        {
            continue;
        }


        printf("%s\n",entry->d_name);
    }

    closedir(dp);

    return 0;
}