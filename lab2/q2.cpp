#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
	
	char res[100];
	char* path;
	
	path = getcwd(res, 100);
	
	printf("Res : %s \n", res);
	printf("Path : %s \n", path);
	
	return 0;
}
