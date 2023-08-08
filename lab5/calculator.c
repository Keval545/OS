#include <pthread.h>
#include <stdio.h>
#include <malloc.h>



struct stru{
  int a;
  int b;
};
 
 void* add(void *p){
 	struct stru* pt = (struct stru* )p;
 	printf("addition of two number is\n");
 	printf("%d\n",pt->a+pt->b);
 	return NULL;
 }
 
 void* mul(void *p){
 	struct stru* pt = (struct stru* )p;
 	printf("multiplication of two number is\n");
 	printf("%d\n",pt->a*pt->b);
 	return NULL;
 }
 
 void* sub(void *p){
 	struct stru* pt = (struct stru* )p;
 	printf("subtraction of two number is\n");
 	printf("%d\n",pt->a-pt->b);
 	return NULL;
 }
 
 void* div(void *p){
 	struct stru* pt = (struct stru* )p;
 	printf("division of two number is\n");
 	float f = (float)pt->a/pt->b;
 	printf("%f\n",f);
 	return NULL;
 }
 
 
 void main(){
 	
 	int x,y,z,w;
 	pthread_t t1,t2,t3,t4;
 	struct stru st = {9,5.0};
 	struct stru *s_p = &st;
 	void *ptr = (void* )s_p;
 	x = pthread_create(&t1, NULL, add, ptr);
 	int a = pthread_join(t1, NULL);
 	y = pthread_create(&t2, NULL, mul, ptr);
 	int b = pthread_join(t2, NULL);
 	z = pthread_create(&t3, NULL, sub, ptr);
 	int c = pthread_join(t3, NULL);
 	w = pthread_create(&t4, NULL, div, ptr);
 	int d = pthread_join(t4, NULL);
 	
 	return;
 
 }
 

