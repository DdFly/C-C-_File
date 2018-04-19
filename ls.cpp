#include <stdio.h>  
#include <stdlib.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <dirent.h>  
void do_ls(char dirname[]);  
void show_info(char *fname, struct stat * buf);  
int main(int ac, char *av[]) { 
    if(ac == 1) 
	{ 
	    do_ls("."); 
		   
	} 
	else 
	    while(--ac){ 
		    printf("%s:/n",*++av); 
			do_ls(*av); 
	    } 
} 
 /*the ls function,list the the files of the directory*/ 
 void do_ls(char dirname[]) { 
	DIR *dir_pty; 
	struct dirent *direntp; /*pointer of the dirent       struct*/
	struct stat stat_buff; 
	int count = 0; /*the counter */
	dir_pty = opendir(dirname); /*open the dir*/
	if(dir_pty == NULL) 
	{ 
		perror("opendir error"); 
		exit(0); 
	} 
	else { 
	    while((direntp = readdir(dir_pty)) != NULL)  {
		     printf("%s/n",direntp->d_name); 
			 show_info(dirname,&stat_buff); 
			 printf("/n");
		} 
		printf("/n");
		close(dir_pty);
	} 
} 
/*display some information of the file*/
void show_info(char *fname, struct stat * buf) { 
	printf("   mode:%o/n",buf->st_mode); 
	printf("  links:%d/n",buf->st_nlink); 
	printf("   user:%d/n",buf->st_uid); 
	printf("  grout:%d/n",buf->st_gid); 
	printf("   size:%d/n",buf->st_size); 
	printf("modtime:%d/n",buf->st_mtime); 
	printf("   name:%s/n",fname); 
} 
