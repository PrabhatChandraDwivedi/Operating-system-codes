#include <stdio.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <string.h>
#define FIFO_FILE "/tmp/FIFO_server" 
void string_change(char *str) {
char temp[80];
strcpy(temp, "Hello to ACTS");
 int ret=strcmp(str, temp);
if (ret==0){
strcpy(str, "Hello to CDAC");
}
return;
}

void main()
 {
 int fd;
char str, readbuf[80];
 char exit[10];
int to_end;
int read_bytes;

mkfifo(FIFO_FILE, S_IFIFO|0640);
strcpy(exit, "end");

fd = open(FIFO_FILE, O_RDWR);

 printf("Starting\n");
while(1) {
read_bytes = read(fd, readbuf, sizeof(readbuf));
 readbuf[read_bytes] = '\0';
printf("Received message: %s\n",readbuf);
 to_end = strcmp(readbuf, exit);
if (to_end == 0) {
close(fd);
 break;
}
string_change(readbuf);

printf("Sending back the string: %s\n", readbuf);
 write(fd, readbuf, strlen(readbuf));
sleep(4);

}

}
