#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void main(){
char * naam[] ={"/home/prabhat/OS_17_mar/nn.sh",0};
//pid_t a=fork();
//if(a==0){
execv(naam[0], naam);

/*}
else if(a<0){
printf("Child labour is wrong, FBI!, open up!!\n");

}
else{
wait(0);
}*/


}
