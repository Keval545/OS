#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {

	int n;
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++) {
		int pid = fork();
		if(pid == -1){
			printf("fails");
		}
		else{
		if(pid == 0) {
			wait(NULL);	
		}
		else if(pid > 0) {
			int a = getpid();
			int b = getppid();			
			printf("child : %d and parent : %d\n", a, b);
			exit(0);
		}
		}
	}

	return 0;
}
	
