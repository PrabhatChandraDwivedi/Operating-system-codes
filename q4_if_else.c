#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
void main() {
pid_t a=fork();
if(a==0){
sleep(5);
printf("my parent id is %d\n",getppid());

}
else{
printf("hello\n");
exit(0);
}

}
