#include<stdio.h>
#include<unistd.h>

int main() {
	
	
	while(1) {
		char arr[50];
	
		int n = read(0, arr, 50);
		write(1, arr, n);
	}
	
	return 0;
}

