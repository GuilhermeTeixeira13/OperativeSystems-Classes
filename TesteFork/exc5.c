#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    FILE *fp = fopen("out.txt","w");
    fprintf(fp,"Bom Dia");

    if (0 == fork())
    {
        fprintf(fp, "Child Process\n");
        fclose(fp);
    }
    else
    {
        fprintf(fp,"Parent Process\n");
    }
    return 0;
}