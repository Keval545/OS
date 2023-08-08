 #include <pthread.h>
 #include <stdio.h>
 #include <malloc.h>

 int count = 0;
 pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
 void * printhello(){
 	int temp = pthread_mutex_lock(&m);
 	count++;
 	printf("%d\n",count);
 	int temp2 = pthread_mutex_unlock(&m);
 	return NULL;
 }

void main(){
	pthread_t t[5];
 	for(int i =0; i < 5; i++)
	{
		int x = pthread_create(&t[i], NULL, printhello, NULL);
		
	}
	for(int i =0; i < 5; i++)
	{
		
		int p = pthread_join(t[i], NULL);
	}

 return;
}
