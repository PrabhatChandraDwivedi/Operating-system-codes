#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
void main(){
pid_t a=fork();
switch (a){
case -1: printf("bad fork\n");
	break;
case 0: printf("I am a child\n");
//	printf("my parent id is %d\n", getppid());
//	printf("And my pid is %d\n",getpid());
	sleep(5);
//	printf("my new pid is %d\n", getpid());
	printf("My new parent id is %d\n", getppid());
	break;
case 1: printf("hello\n");
	break;
default:// printf("I am a parent\n");
//	sleep(2);
	printf("original pid is %d\n", getpid());
//	printf("my parent id is %d\n", getppid());

}
}
