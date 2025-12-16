#include <unistd.h>     // fork, pipe, dup2, execve
#include <fcntl.h>      // open
#include <sys/wait.h>   // waitpid
#include <stdlib.h>     // exit
#include <stdio.h>      // perror

int main(int ac, char **av)
{
	int infile;
	int outfile;

	if (ac != 5)
		return (1);
	//file1 i okuyoruz okuma ucu
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		return (perror("infile"), 1);
	//file2 yazma yazma ucu , yoksa oluştur varsa sil
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		return (perror("outfile"), 1);
	//aç ve kapa
	close(infile);
	close(outfile);
	return (0);
}
