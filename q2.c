#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int a=2;
void main(){
pid_t b=fork();
wait(0);
if (b==0){
a=a+7;
printf("child pid is %d\n", getpid());
printf("value of a in child is %d\n", a);
}
else {
printf("parent pid is %d\n",getpid());
printf("value of a in parent is %d\n",a);
}


}
