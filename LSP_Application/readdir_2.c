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

        printf("Inode number : %ld \n",ptr->d_ino);
        printf("File name : %s \n",ptr->d_name);
    }
    
    closedir(dp);
    return 0;
}