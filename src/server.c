/*******************************
 * Named Pipe example code     *
 * *****************************
 * Author: Luis Lourenco, 2014 *
 * ****************************/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(){

  int num;
  char temp[38];
  int fifo = mkfifo("fifo", S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
  if ((fifo = open("fifo", O_RDONLY)) < 0)
  {
    printf("%s\n", strerror(errno));
    return;
  }
  while (1) 
  {
    if ((num = read(fifo, temp, sizeof(temp))) < 0) 
    {
      printf("%s\n", strerror(errno));
    }
    if (num > 0) printf("RECEIVED(%d): %s \n", num, temp);
    usleep(100000);
  }
  close(fifo);
}
