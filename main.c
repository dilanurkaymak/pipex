#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		pipe_end[2];
	pid_t	pid;

	if (ac != 5)
		error_exit("Usage: ./pipex infile cmd1 cmd2 outfile");
	if (pipe(pipe_end) == -1)
		error_exit("pipe");
	pid = fork();
	if (pid == 0)
		exec_input(pipe_end, av, envp);
	pid = fork();
	if (pid == 0)
		exec_output(pipe_end, av, envp);
	close(pipe_end[0]);
	close(pipe_end[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
