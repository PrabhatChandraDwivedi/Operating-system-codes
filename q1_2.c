#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void main() {
pid_t a,b,c;
printf ("L0\n");
a=fork();
wait(0);
if(a==0){
printf("L1\n");
printf("bye1\n");
}

else {
b=fork();
wait(0);
	if(b==0){
	printf("L2\n");
	c=fork();
	wait(0);
	printf("bye\n");
	}

	else{
	printf("bye4\n");
	}
}







}
