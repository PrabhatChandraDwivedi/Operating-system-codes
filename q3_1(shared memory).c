#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) 
{
int shmid ;
char buff[100];
void *shmp;
shmid = shmget((key_t)2546, 1024, 0644|IPC_CREAT);
printf("Key of Shared Memory is: %d\n", shmid);
if (shmid == -1) 
 {
  perror("Shared memory");
  return 1;
 }

shmp = shmat(shmid, NULL, 0);
if (shmp == (void *) -1)
 {
  perror("Shared memory attach");
  return 1;
 }

printf("Process Attached at: %p\n", shmp);
printf("Enter data into Shared Memory\n");
read(0,buff, 100);
strcpy(shmp,buff);

printf("You wrote: %s\n", (char *)shmp);


if (shmdt(shmp) == -1)
 {
  perror("shmdt");
  return 1;
 }

printf("Writing Process: Completed\n");
return 0;
}
