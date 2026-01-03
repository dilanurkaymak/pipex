/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:36:30 by dkaymak           #+#    #+#             */
/*   Updated: 2026/01/03 18:59:09 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void cmd_not_found(char *cmd)
{
    write(2, "pipex: command not found: ", 26);
    if (cmd)
        write(2, cmd, ft_strlen(cmd));
    write(2, "\n", 1);
    exit(127);
}

void    exec_cmd(char *cmd, char **envp)
{
    char    **args;
    char    *path;

    if (!cmd || !*cmd)
        cmd_not_found(cmd);
    args = ft_split(cmd, ' ');
    if (!args || !args[0])
    {
        ft_free_split(args);
        cmd_not_found(cmd);
    }
    path = find_path(args[0], envp);
    if (!path)
    {
        char *failed_cmd = ft_strdup(args[0]); // Adını sakla
        ft_free_split(args);
        cmd_not_found(failed_cmd); // Hangi komut olduğunu yazdır
    }
    execve(path, args, envp);
    // Eğer buraya gelirse execve başarısız olmuştur
    error_exit(args[0], 126);
}
