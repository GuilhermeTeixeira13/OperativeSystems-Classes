#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>

/* Detect PIPE SYMBOL in array of Strings return its index or -1 if it does not exist */
int containsPipe(int numArgs, char **args)
{
  int index;
  for (index = 0; index < numArgs; index++)
    if (args[index][0] == '|')
    {
      return index;
    }
  return -1;
}
int main()
{
  int indice, pidFilho, fd[2], numArgs;
  // char *myargs[] = {"ls", "-l", "-a", NULL};
  char *myargs[] = {"ls", "-l", "-a", "|", "wc", "-c", NULL};
  // char *myargs[] = {"cat", "-t", "/etc/passwd", "|", "grep", "-v", "root", NULL};

  char **args = myargs;
  numArgs = // 3,6 ou 7
      indice = containsPipe(numArgs, args);
  if (indice == -1)
    execvp(*args, args);
  if (indice > 0)
  {
    printf("pipe detected at index %d\n", indice);
    printf("Remove PIPE symbol. Create Pipe. Fork(). Exec in 2 Processes\n");
    args[indice] = NULL;
    pipe(fd);
    pidFilho = fork();
    if (pidFilho == 0)
    { // write
      numArgs = indice;
      fprintf(stderr, "cmd write to pipe: %s numArgs=%d\n", args[0], numArgs);
      dup2(fd[1], STDOUT_FILENO);
      close(fd[0]);
      close(fd[1]);
    }
    else
    { // read
      args = args + indice + 1;
      numArgs = numArgs - indice - 1;
      fprintf(stderr, "cmd read from pipe: %s numArgs=%d\n", args[0], numArgs);

      dup2(fd[1], STDIN_FILENO); // duplicar o descritor de ficheiro de leitura do PIPE para a posição na tabele de FD do STDIN
      close(fd[1]);
      close(fd[0]); // fechar o descritor do ficheiro do pipe que este processo não necessita.
    }
    execvp(); // Chamar a função execvp() para executar os comandos agora ligados via um pipe.
  }
  return 0;
}
