/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:35:40 by dkaymak           #+#    #+#             */
/*   Updated: 2026/01/03 18:59:03 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

void	error_exit(char *msg, int code);
char	*find_path(char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);

#endif
