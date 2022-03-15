#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

    int v[10];

    int descriptor = 0;

    descriptor = open("test.bin", O_RDONLY);

    read(descriptor, v, sizeof(int)*10);
    
    printf("Array de inteiros lido: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);   
    }
    printf("\n");
       
    close(descriptor);

    return 0;
}