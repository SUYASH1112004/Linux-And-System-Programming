#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>


int main()
{

    DIR *dp = NULL;

    dp = opendir("./Data");
    struct dirent * ptr = NULL;

    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
    
    while(ptr = readdir(dp))
    {

        // fd = open(ptr->d_name,O_RDONLY);
        // iRet = 
    }
    
    closedir(dp);
    return 0;
}