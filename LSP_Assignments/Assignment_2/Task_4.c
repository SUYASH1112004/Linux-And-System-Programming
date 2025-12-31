#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>
#include<sys/syscall.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    DIR *dp;
    char name[100];
    char path[500];
    dp = NULL;

    struct dirent *entry;
    struct stat buff;

    printf("Enter the name of directory \n");
    scanf("%s",name);

    dp = opendir(name);

    if(dp == NULL)
    {
        printf("%s",strerror(errno));
        return 1;
    }



    while((entry=readdir(dp))!=NULL)
    {

        printf("-----------------------\n");
        printf("Name : %s\n",entry->d_name);

        snprintf(path,sizeof(path),"%s/%s",name,entry->d_name);
        lstat(path, &buff);

        switch(buff.st_mode & S_IFMT)
        {
            case S_IFBLK :
                printf("Block Device \n");
                break;
            
            case S_IFCHR :
                printf("Character Device \n");
                break;

            case S_IFDIR :
                printf("Directory File \n");
                break;
        
            case S_IFIFO :
                printf("FIFO Pipe  \n");
                break;

            case S_IFLNK :
                printf("Symbolic Link \n");
                break;

            case S_IFREG :
                printf("Regular File\n");
                break;            
            
            case S_IFSOCK :
                printf("Socket files\n");
                break;

            default:
                printf("Unknown\n");
                break;
    
        }    
        printf("-----------------------\n");

    }

    closedir(dp);

    return 0;
}