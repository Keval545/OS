#include <pthread.h>
#include <stdio.h>
#include <malloc.h>
 
void* printhello(void *p){
 	char* pt = (char* )p;
 	printf("%s\n",pt);
 	return NULL;
 }
 
 
 void main(){
 	
 	pthread_t t1;
 	char arr[10] = "helloworld";
 	void *ptr = (void *)arr;
 	int x = pthread_create(&t1, NULL, printhello, ptr);
 	int z = pthread_join(t1, NULL);
 	
 	return;
 
}

