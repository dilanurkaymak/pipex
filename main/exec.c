/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:36:30 by dkaymak           #+#    #+#             */
/*   Updated: 2026/01/04 12:30:00 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	cmd_not_found(char *cmd, char **args)
{
	write(2, "pipex: ", 7);
	if (cmd)
		write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	ft_free_split(args);
	exit(127);
}

static char	*get_cmd_path(char **args, char **envp)
{
	if (ft_strchr(args[0], '/'))
		return (ft_strdup(args[0]));
	return (find_path(args[0], envp));
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || !*cmd)
		cmd_not_found(NULL, NULL);
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		cmd_not_found(NULL, args);
	path = get_cmd_path(args, envp);
	if (!path || access(path, F_OK) == -1)
	{
		free(path);
		cmd_not_found(args[0], args);
	}
	execve(path, args, envp);
	perror("pipex");
	free(path);
	ft_free_split(args);
	exit(126);
}
