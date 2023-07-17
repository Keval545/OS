#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
	
	DIR * dr;
	dr = opendir(argv[1]);
	
	struct dirent *dptr;
	
	dptr = readdir(dr);
	
	while(dr != NULL) {
		struct dirent *dptr = readdir(dr);
		printf("%s \n", dptr->d_name);
	}
	return 0;
}

