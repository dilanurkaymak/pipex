#include "pipex.h"
#include "libft/libft.h"

void	exec_input(int *pipe_end, char **av, char **envp)
{
	int		in;
	char	**cmd;
	char	*path;

	in = open(av[1], O_RDONLY);
	if (in < 0)
		error_exit("infile");
	dup2(in, STDIN_FILENO);
	dup2(pipe_end[1], STDOUT_FILENO);
	close(pipe_end[0]);
	cmd = ft_split(av[2], ' ');
	path = find_path(cmd[0], envp);
	execve(path, cmd, envp);
	error_exit("execve");
}

void	exec_output(int *pipe_end, char **av, char **envp)
{
	int		out;
	char	**cmd;
	char	*path;

	out = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (out < 0)
		error_exit("outfile");
	dup2(pipe_end[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(pipe_end[1]);
	cmd = ft_split(av[3], ' ');
	path = find_path(cmd[0], envp);
	execve(path, cmd, envp);
	error_exit("execve");
}
