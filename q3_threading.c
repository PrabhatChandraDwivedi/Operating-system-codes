#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>

#define NUM_THREAD 1

void *arraysum(void *threadid){
int n,sum=0;
printf("Enter the size of array\n");
scanf("%d",&n);
int * arr;
arr=(int * )malloc(n*sizeof(int));
printf("Enter the elements of array\n");
for(int i=0;i<n;i++){
scanf("%d",arr + i);
}

for(int j=0;j<n;j++){
sum=sum+arr[j];
}
printf("The value of sum is %d \n", sum);
pthread_exit(NULL);
}
int main(){
pthread_t threads[NUM_THREAD];
int rc;
long t;
for(t=0;t<NUM_THREAD;t++){
rc=pthread_create(&threads[t], NULL, arraysum, (void * )t);
}
pthread_exit(NULL);
}
