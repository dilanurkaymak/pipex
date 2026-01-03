/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:36:30 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/28 18:04:14 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	cmd_not_found(void)
{
	write(2, "pipex: command not found\n", 27);
	exit(127);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || !*cmd)
		cmd_not_found();
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		ft_free_split(args);
		cmd_not_found();
	}
	path = find_path(args[0], envp);
	if (!path)
	{
		ft_free_split(args);
		cmd_not_found();
	}
	execve(path, args, envp);
	perror("pipex");
	ft_free_split(args);
	free(path);
	exit(126);
}
