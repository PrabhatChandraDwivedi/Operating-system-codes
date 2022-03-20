#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
void main()
{
printf ("L0\n");
pid_t q=fork();
if (q<0){
printf("child process did not get created\n");
}
else if (q==0) {
	printf ("Bye\n");
}
else  {
	printf("L1\n");
	pid_t r = fork();

	if (r<0){
		printf("second child did not get created");
	   }
	
	else if(r==0){
		printf("Bye\n");	
	}
	else {
	printf("L2\n");
	fork();
	printf("Bye\n");
	}
 
}









}
