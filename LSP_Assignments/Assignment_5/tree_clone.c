#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>


void printIndent(int count)
{
    for(int i = 0;i<count;i++)
    {
        printf("    ");
    }
}

void tree(int indent,char *path)
{
    DIR * dp;
    struct dirent *entry; 
    struct stat sb;
    char fullpath[1024];

    dp=opendir(path);

    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return ;
    }

    while((entry = readdir(dp))!=NULL)
    {
        if(((strcmp(".",entry->d_name))==0) || ((strcmp("..",entry->d_name))==0))
        {
            continue;
        }

        snprintf(fullpath,sizeof(fullpath),"%s/%s",path,entry->d_name);

        if(lstat(fullpath,&sb)==-1)
        {
            printf("%s\n",strerror(errno));
            return ;
        }

        printIndent(indent);

        if(S_ISDIR(sb.st_mode))
        {
            printf("[D] %s/\n",entry->d_name);
            tree(indent+1,fullpath);
        }

        else if(S_ISLNK(sb.st_mode))
        {
            printf("[L] %s\n",entry->d_name);
        }

        else if(S_ISREG(sb.st_mode))
        {
            printf("[R] %s\n",entry->d_name);
        }

        else
        {
            printf("[?] %s\n",entry->d_name);
        }
    }

    closedir(dp);



}



int main()
{

    char name[100];
    printf("Enter the name of directory : \n");
    scanf("%s",name);

    tree(1,name);

    

    return 0;
}