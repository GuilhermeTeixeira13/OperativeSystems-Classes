// ./exc71

#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h> 
#include <unistd.h>
#include <stdlib.h>
extern int errno; 

int main() 
{     

  // The file descriptor returned
  // by a successful call will be the lowest-numbered file
  // descriptor not currently open for the process
  int fd = open("test.bin", O_RDONLY);
  printf("fd = %d\n", fd); 
      
  if (fd == -1){ 
    printf("Error Number % d\n", errno);  
    perror("Program");                 
  }  

  //  É reservada memória para uma array de inteiros com o malloc()
  //  A cada conjunto de 4 bytes (sizeof(int()) que a função
  // read() lê, é reservada mais uma casa no array de inteiros
  // e nessa casa reservada é escrito o conteúdo desses 4 bytes lidos pelo read()

  // read(1, 2, 3)
  // 1 - The file descriptor of where to read the input.
  // 2 - Where the read content will be stored.
  // 3 - The number of bytes to read before truncating the data.
  // return - Returns the number of bytes that were read.

  ssize_t n = 0;
  int num; 
  int pos=0;

  int *arrayLidos = (int*)malloc(sizeof(int));;
  while ((n = read(fd, &num, sizeof(int))) > 0) { 
    pos++;
    arrayLidos = realloc(arrayLidos, pos * sizeof(int));
    arrayLidos[pos-1] = num;      
  }

  if (n == -1) {
    perror("read");
    exit(1);
  }
  if (close(fd) == -1) {
    perror("close");
    exit(1);    
  }

  // Imprimir os valores guardados no array
  for(int i=0; i<10; i++){
    printf("%d/", arrayLidos[i]);
  }

  exit(0);
  return 0; 
} 