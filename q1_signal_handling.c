#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


void sidefunction(){
printf("Received SIGUSR1 signal, going to sleep for 5 seconds\n");
sleep(5);
}


void main(){

signal(SIGUSR1,sidefunction);
pid_t a=fork();
       if(a==0){
	

	sleep(1);
		kill(getppid(),SIGUSR1);
	}
	else{
	
	     for(int i=0;i<=200000;i++){
		printf("The value of I is %d\n",i);
		
		}

	}

}
