#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void func1(){
printf("this is the first handling\n");
}
void func2(){
printf("this is the second handling\n");
}

void main(){
signal(SIGINT,func1);
signal(SIGTERM,func2);
kill(getpid(),SIGINT);
kill(getpid(),SIGTERM);
}
