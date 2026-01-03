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

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free_split(char **arr);
size_t	ft_strlen(const char *s);

void 	cmd_not_found(char *cmd);
void	error_exit(char *msg, int code);
char	*find_path(char *cmd, char **envp);
void    exec_cmd(char *cmd, char **envp);

#endif
