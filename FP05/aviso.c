#include <stdio.h>
#include <stdlib.h>

void aviso(char *mesg, int tempo)
{
  while (tempo > 0)
  {
    sleep(1);
    tempo--;
  }
  fprintf(stderr, "Aviso : %s\n", mesg);
}