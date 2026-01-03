/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:36:45 by dkaymak           #+#    #+#             */
/*   Updated: 2026/01/03 18:56:22 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1(int *pipefd, char **av, char **envp)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
	{
		write(2, "pipex: ", 7);
        perror(av[1]);
		infile = open("/dev/null", O_RDONLY);
	}
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(infile);
	close(pipefd[0]);
	close(pipefd[1]);
	exec_cmd(av[2], envp);
}

static void	child2(int *pipefd, char **av, char **envp)
{
	int	outfile;

	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error_exit(av[4], 1);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(pipefd[0]);
	close(pipefd[1]);
	exec_cmd(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (ac != 5)
		return (1);
	if (pipe(pipefd) < 0)
		error_exit("pipe", 1);
	pid1 = fork();
	if (pid1 == 0)
		child1(pipefd, av, envp);
	pid2 = fork();
	if (pid2 == 0)
		child2(pipefd, av, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
