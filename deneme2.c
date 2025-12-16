#include <unistd.h>

int main(void)
{
    int fd[2];
    pipe(fd);

    if (fork() == 0)
    {
        dup2(fd[1], 1);
        execlp("echo", "echo", "hello", NULL);
    }
}
