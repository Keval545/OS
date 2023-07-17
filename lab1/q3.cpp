#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {

	int n1 = open(argv[1], O_RDONLY);
	int n2 = open(argv[2], O_WRONLY);
	
	if(n1 < 0) {
		write(1, "fails by n1", 11);
	}
	else if(n2 < 0) {
		write(1, "fails by n2", 11);
	}
	else {
		
		char arr[500];
		int p = read(n1, arr, 500);
		write(n2, arr, p);
		
	}
		
	return 0;
}


