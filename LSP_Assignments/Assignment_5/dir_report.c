#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<errno.h>


void solve(char *name, int *fcnt,int *dcnt,long *size,char * largestname,long *lsize)
{
    char path[1024];

    DIR *dp;
    struct dirent *create;
    struct stat sb;
    dp = opendir(name);

    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return ;
    }

    while((create=readdir(dp))!=NULL)
    {
        if(strcmp(create->d_name,".")==0 || strcmp(create->d_name,"..")==0)
        continue;

        snprintf(path,sizeof(path),"%s/%s",name,create->d_name);
        
        if(lstat(path,&sb) ==-1)
        {
            printf("%s\n",strerror(errno));
            return ;
        }

        else if(S_ISDIR(sb.st_mode))
        {
            (*dcnt)++;
            solve(path,fcnt,dcnt,size,largestname,lsize);
        }
        else if(S_ISREG(sb.st_mode))
        {
            (*fcnt)++;
            (*size)+=sb.st_size;
            
            if(sb.st_size>*lsize)
            {
                *lsize=sb.st_size;
                strcpy(largestname, create->d_name);

            }
        }
        else if(S_ISLNK(sb.st_mode))
        {
            (*fcnt)++;
        }


    }
    closedir(dp);

}


int main()
{
    char name[100];

    printf("Enter the directory name : \n");
    scanf("%s",name);


    int fcnt=0,dcnt = 0;
    long size = 0;
    char largestname[100];
    long lsize = 0;

    solve(name,&fcnt,&dcnt,&size,largestname,&lsize);

    printf("Total Number Of Files : %d \n",fcnt);
    printf("Total No of Directories : %d \n",dcnt);
    printf("Total size of regular files : %ld \n",size);
    printf("Largest File Name : %s\nLargest Size : %ld\n",largestname,lsize);
    


    return 0;
}