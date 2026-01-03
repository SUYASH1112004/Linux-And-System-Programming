#include<stdio.h>
#include<sys/syscall.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>
#include<string.h>
#include<errno.h>

int main()
{
    char name[100];
    char path[400];

    printf("Enter Directory : \n");
    scanf("%s",name);

    DIR *dp;
    struct dirent *entry;
    struct stat st;

    dp = opendir(name);
    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }

    while((entry=readdir(dp))!=NULL)
    {

        if(((strcmp(".",entry->d_name))==0) || ((strcmp("..",entry->d_name))==0))
        {
            continue;
        }

        snprintf(path,sizeof(path),"%s/%s",name,entry->d_name);
        printf("Entry Name : %s \n",path);
        lstat(path,&st);
        switch (st.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }

        printf("Size : %ld \n",st.st_size);

        printf("Permission : ");
        //user
        printf((st.st_mode & S_IRUSR) ? "r" : "-");
        printf((st.st_mode & S_IWUSR) ? "w" : "-");
        printf((st.st_mode & S_IXUSR) ? "x" : "-");

        /* Group */
        printf((st.st_mode & S_IRGRP) ? "r" : "-");
        printf((st.st_mode & S_IWGRP) ? "w" : "-");
        printf((st.st_mode & S_IXGRP) ? "x" : "-");

        /* Others */
        printf((st.st_mode & S_IROTH) ? "r" : "-");
        printf((st.st_mode & S_IWOTH) ? "w" : "-");
        printf((st.st_mode & S_IXOTH) ? "x" : "-");
        printf("\n");


        printf("Last modified time : %s\n",ctime(&st.st_mtime));

    }


    return 0;
}