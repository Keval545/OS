#include <pthread.h>
#include <stdio.h>
#include <malloc.h>
 
void * printhello(){
 	printf("hello from thread 1\n");
 	return NULL;
}
 
void * printhellofrom2(){
 	printf("hello from thread 2\n");
 	return NULL;
}
 
 void main(){
 	
 	pthread_t t1,t2;
 	int x = pthread_create(&t1, NULL, printhello, NULL);
 	
 	int y = pthread_create(&t2, NULL, printhellofrom2, NULL);
 	int p = pthread_join(t1, NULL);
 	int q = pthread_join(t2, NULL);
 	//best approach to use 2 thread creation in bellow
 	//create
 	//create
 	//join
 	//join
 	
 	return;
 
 }

