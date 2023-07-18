#include <sys/types.h>
#include <unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main(){
	int pid;
	pid = fork();
	int p = getpid();
	int q ;
	if(pid == -1){
		printf("fails");
}
	if(pid == 0){
		q = getpid();
		printf("hello from child : %d of parent :%d\n",getpid(),getppid());
	}
	else{
		printf("hello from parent :%d of child : %d\n",p,pid);
		
	}
	
	return 0;
}


