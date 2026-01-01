#include<stdio.h>
// #include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include <sys/syscall.h> 
#include<dirent.h>

int main()
{

    char name[100];
    char buff[400];



    DIR *dp;
    int cnt = 0;

    struct dirent *entry;
    struct stat st;

    printf("Enter the Directory Name : \n");
    scanf("%s",name);

    dp=opendir(name);


    while((entry=readdir(dp))!= NULL)
    {
        if((strcmp(".",entry->d_name) == 0) || (strcmp("..",entry->d_name) == 0))
        {
            continue;
        }

        snprintf(buff,sizeof(buff),"%s/%s",name,entry->d_name);

        stat(buff,&st);

        if(S_ISREG(st.st_mode) && st.st_size == 0)
        {
            cnt++;
            printf("%s\n",entry->d_name);
            unlink(buff);
            cnt++;
        }
    }

    printf("Total no of files deleted : %d \n",cnt);

    


    return 0;
}