#include <stdio.h>
void streamCopy ( FILE * entrada, FILE * saida);
int main( int argc, char *argv[] ){
 
 if ( 1 == argc ) 
 streamCopy ( stdin, stdout); 
 //else abrir ficheiros – exercício
 return 0;
}
void streamCopy ( FILE * entrada, FILE * saida ){
 int ch; 
 while ( (ch=fgetc(entrada)) != EOF ){
 fputc( ch, saida);
 }
}
