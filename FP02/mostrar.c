#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void streamCopy ( FILE * entrada, FILE * saida);
void alteraCharControlo ( FILE * entrada, FILE * saida );


int main( int argc, char *argv[] ){
 
  if ( 1 == argc ) 
    streamCopy (stdin, stdout); 
  else {
    FILE *fptr1;
    int start=1;
    if(strcmp(argv[1], "-T") == 0){
      start = 2; 
    }
    for(int i=start; i< argc; i++){
      fptr1 = fopen(argv[i], "r");
      if (fptr1 == NULL){
        printf("Cannot open file %s \n", argv[i]);
        exit(0);
      }

      if(start==2)
        alteraCharControlo(fptr1, stdout);
      else
        streamCopy(fptr1, stdout);
      fclose(fptr1);
    }
  }

 return 0;
}


void streamCopy ( FILE * entrada, FILE * saida ){
 int ch; 
 while ( (ch=fgetc(entrada)) != EOF ){
 fputc( ch, saida);
 }
}

void alteraCharControlo ( FILE * entrada, FILE * saida ){
 int ch; 
 while ( (ch=fgetc(entrada)) != EOF ){
  if( ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) || (ch >= '0' && ch <= '9'))
    fputc(ch, saida);
  else
    fputc("^I", saida);
 }
}
