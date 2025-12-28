/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:36:30 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/28 17:36:31 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || !*cmd)
		error_exit("command not found", 127);
	args = ft_split(cmd, ' ');
	path = find_path(args[0], envp);
	if (!path)
	{
		ft_free_split(args);
		error_exit("command not found", 127);
	}
	execve(path, args, envp);
	ft_free_split(args);
	free(path);
	error_exit("execve", 126);
}
