#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main() {
pid_t i=fork();
switch(i)
{
case -1: printf("bad fork\n");
	break;
case 0: printf("I am a child\n");
	break;
//case 1: printf("Hello");
	//break;
default: printf("hello I am a parent\n");
	sleep(30);
	break;
}


}
