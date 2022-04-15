#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid, x = 4;
    pid = fork();
    if (0 == pid)
    {
        fork();
        x = x + 2;
    }
    else
    {
        x--;
    }
    printf("x = % d\n", x);
}