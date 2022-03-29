#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "/tmp/FIFO_server"
int main() {
int fd;
int end_process;
int stringlen;
int read_bytes;
char readbuf[80];
char end_str[10];

printf("Send messages, to end enter \"end\"\n");
fd = open(FIFO_FILE, O_CREAT|O_RDWR);
strcpy(end_str, "end");
while (1) {

printf("Enter Message: ");
fgets(readbuf, sizeof(readbuf), stdin);
stringlen = strlen(readbuf);
readbuf[stringlen - 1] = '\0';
end_process = strcmp(readbuf, end_str);

if (end_process != 0) {

write(fd, readbuf, strlen(readbuf));
printf("FROM CLIENT : Sent string is : %s\n", readbuf);
sleep(2);
read_bytes = read(fd, readbuf, sizeof(readbuf));
readbuf[read_bytes] = '\0';
printf("FROM SERVER : Received string is : %s\n", readbuf);
}
else 
{
write(fd, readbuf, strlen(readbuf)); printf("string send: %s\n", readbuf);
close(fd);
break;
}

}

return 0;
}

