#include "pipex.h"
#include "libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	pid_t	pid;

	if (argc != 2)
	{
		write(2, "Usage: ./pipex \"command\"\n", 26);
		return (1);
	}
	px.cmd = argv[1];
	px.cmd_args = ft_split(px.cmd, ' ');
	px.cmd_path = "/bin/ls";
	px.envp = envp;
	pid = fork();
	if (pid == 0)
	{
		execve(px.cmd_path, px.cmd_args, px.envp);
		perror("execve");
		exit(1);
	}
	waitpid(pid, NULL, 0);
	return (0);
}
