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

    char name[200];
    char path[500];
    char max[100];
    int max_size = 0;

    // char sol;

    // struct stat buff;
    struct stat obj;
    DIR *ptr;
    struct dirent *entry;

    printf("Enter the name of directory \n");
    scanf("%s",name);


    ptr=opendir(name);

    if(ptr == NULL)
    {
        printf("%s",strerror(errno));
        return 1;
    }

    while((entry=readdir(ptr))!=NULL)
    {
        snprintf(path,sizeof(path),"%s/%s",name,entry->d_name);
        stat(path,&obj);
        if((obj.st_mode & S_IFMT)== S_IFREG)
        {
            
            if(max_size < obj.st_size)
            {
                max_size=obj.st_size;
                strcpy(max,entry->d_name);
            }
        }

    }

    printf("Max Sized File is : %s\n",max);
    printf("The size of file is : %d \n",max_size);
    


    return 0;
}