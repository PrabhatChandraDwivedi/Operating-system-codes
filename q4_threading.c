#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NUM_THREAD 2

void *thredid(void *t){
while(1){
printf("Hello world %ld\n",pthread_self());
}
pthread_exit(NULL);
}
void main(){
pthread_t threads[NUM_THREAD];

long t;

pthread_create (&threads[0], NULL, thredid,(void * ) t);
pthread_create (&threads[1], NULL, thredid,(void * ) t);

pthread_exit(NULL);
}
