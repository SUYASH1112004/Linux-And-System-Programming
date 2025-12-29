#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main ()
{

    int iRet = 0;

    struct stat Sobj;

    iRet=stat("Demo.txt",&Sobj);

    printf("Inode Number : %lu \n",Sobj.st_ino);

    printf("Hardlink count : %lu \n",Sobj.st_nlink);

    printf("Total Size : : %lu \n",Sobj.st_size);

    printf("Block Size : %lu \n",Sobj.st_blksize);

    printf("File type is : %d \n",Sobj.st_mode);

    if(S_ISBLK(Sobj.st_mode))
    {
        printf("Block Device \n");
    }
    else if(S_ISCHR(Sobj.st_mode))
    {
        printf("Character Device \n");
    }
    else if(S_ISDIR(Sobj.st_mode))
    {
        printf("Directory File");
    }
    else if(S_ISREG(Sobj.st_mode))
    {
        printf("Regular file \n");
    }
    else if(S_ISFIFO(Sobj.st_mode))
    {
        printf("Pipe file \n");
    }
    else if(S_ISSOCK(Sobj.st_mode))
    {
        printf("Socket File \n");
    }
    else if(S_ISLNK(Sobj.st_mode))
    {
        printf("Symbolic link \n");
    }

    return 0;
}