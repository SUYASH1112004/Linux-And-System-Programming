#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<time.h>

int main()
{

    char name[50]={'\0'};

    printf("Enter the name of file : \n");
    scanf("%s",name);

    struct stat buff;

    int val = 0;

    val = stat(name,&buff);

    if(val == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
    

    printf("Size of block : %ld \n",buff.st_blksize);
    printf("Inode number : %ld \n",buff.st_ino);
    printf("Permission of files : %o \n",buff.st_mode & 0777 );
    printf("Owner uid : %d \n",buff.st_uid);
    printf("Owner gid : %d \n",buff.st_gid);

    printf("Last access time : %s \n",ctime(&buff.st_atim.tv_sec));
    printf("Last modified time : %s \n",ctime(&buff.st_mtim.tv_sec));

    // printf("Type of file : %d \n",buff.st_mode);

    if(S_ISREG(buff.st_mode))
    {
        printf("File type : Regular type file \n");
    }
    else if(S_ISDIR(buff.st_mode))
    {
        printf("File type : Directory file \n");
    }
    else if(S_ISCHR(buff.st_mode))
    {
        printf("File type : Character Device \n");
    }
    else if(S_ISBLK(buff.st_mode))
    {
        printf("File type : Block Device \n");
    }
    else if(S_ISLNK(buff.st_mode))
    {
        printf("File type : Symbolic link \n");
    }




    return 0;
}
