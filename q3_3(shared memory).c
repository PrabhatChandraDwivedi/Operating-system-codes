#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{

void *shmp;
char buff[100];
int shmid;
shmid=shmget((key_t)2546, 1024, 0644);
printf("Key of shared memory is %d\n",shmid);
shmp=shmat(shmid,NULL,0);
printf("Process attached at %p\n",shmp);
printf("Process 2 reading data from shared memory is : %s\n",(char *)shmp);


if (shmdt(shmp) == -1)
{
  perror("shmdt");
  return 1;
}
}
