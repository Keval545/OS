#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>


void recur(char *path){
	DIR* d = opendir(path);
	struct dirent *de = readdir(d);
	while(de != NULL){
		char next[1000];
		strcpy(next, path);
		strcat(next, "/");
		strcat(next, de->d_name);
		printf("%s\n", next);
		
		if((de->d_name)[0] != '.' && de->d_type == DT_DIR){
			recur(next);
		}
		
		de = readdir(d);
	}
}

int main(int argc, char* argv[]){
	char buff[1000];
	getcwd(buff, 1000);
	if(argc == 2){
		recur(argv[1]);
	}
	else{
		recur(buff);
	}
	
	
	return 0;
}

