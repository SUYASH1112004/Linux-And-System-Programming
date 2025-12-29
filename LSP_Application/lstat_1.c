#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main ()
{

    int iRet = 0;

    struct stat Sobj;

    iRet =  lstat("./LSPL.txt",&Sobj);

    printf("Inode Number : %lu \n",Sobj.st_ino);

    printf("Hardlink count : %lu \n",Sobj.st_nlink);

    printf("Total Size : : %lu \n",Sobj.st_size);

    printf("Block Size : %lu \n",Sobj.st_blksize);

    printf("File type is : %d \n",Sobj.st_mode);
    return 0;
}