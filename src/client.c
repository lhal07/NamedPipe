/*******************************
 * Named Pipe example code     *
 * *****************************
 * Author: Luis Lourenco, 2014 *
 * ****************************/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv){

  int num, fifo;
  char phrase[50];
  strcpy(phrase,argv[1]);
  if ((fifo = open("fifo", O_WRONLY)) < 0) {
    printf("%s\n", strerror(errno));
    return;
  }
  if ((num= write(fifo, phrase, strlen(phrase)+1)) < 0) {
    printf("ERROR: %s\n", strerror(errno));
  }
  close(fifo);

}
