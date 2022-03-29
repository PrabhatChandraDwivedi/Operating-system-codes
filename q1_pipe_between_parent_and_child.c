#include<unistd.h>
#include<stdio.h>
void main()
{
int fds1[2];
int fds2[2];
char write_msg[2][20]={"Hello","CDAC"};
char read_msg[20];
int status= pipe(fds1);
int status1= pipe(fds2);
pid_t v=fork();
if (v==0)
  {
    close(fds1[1]);
    close(fds2[0]);
    printf("Currently in child  : writing to pipe 2\n");
    write(fds2[1],write_msg[1],sizeof(write_msg[1]));
    read(fds1[0],read_msg,sizeof(read_msg));
    printf("reading from  parent, pipe 1 >  message 1 is  %s\n",read_msg);
  }
else if (v>1)
  {
     close(fds1[0]);
     close(fds2[1]);
     printf("Currently in parent : writing to pipe 1 \n");
     write(fds1[1],write_msg[0],sizeof(write_msg[0]));
     read(fds2[0],read_msg,sizeof(read_msg));
     printf("reading from child, pipe 2 >  message 2 is  %s\n",read_msg);
  }
else
  {
    printf("error in creating the pipe\n");
  }
}
