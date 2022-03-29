#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 128
struct msgbuf
{
long mtype;
char mtext[MAXSIZE];
};

void main()
{
int msqid;
key_t key;
struct msgbuf rcvbuffer;
key = 4321;
if ((msqid = msgget(key, 0644)) < 0)
   {
    perror("msgget()"); exit(1);
   }

//Receive message from process 2
if (msgrcv(msqid, &rcvbuffer, MAXSIZE, 2, 0) < 0)
  {
    perror("msgrcv"); exit(1);
  }
printf("mesage received from server : %s\n", rcvbuffer.mtext);
exit(0);
}
