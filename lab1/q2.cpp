#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
	
	for(int i=1 ; i<=argc ; i++) {
	
		int n = open(argv[i], O_RDONLY);
		
		
		if(n>0) {
			char arr[500];
			int p = read(n, arr, 500);
			write(1, arr, p);
		}
		else {
			write(1, "Fail", 4);
		}
		printf("%d", close(n));
	}
	
return 0;
}
