//main.c
#include "soio.h"
#include <unistd.h>
int main(){
 SOFILE * fp; char c;
 fp = sofopen("test.txt","w");
 write (1, "Primeiro Caracter ", 18);
 c = sofgetc (fp);
 write (1, &c, 1);
 write (1, "\n", 1);
 write (1, "Resto do ficheiro:\n", 19);
 while ( (c = sofgetc(fp)) !=EOF )
 write( 1, &c, 1 );

 sofputc(fp, 'o');
 sofputc(fp, 'l');
 sofputc(fp, 'a');

 sofclose(fp);
}
