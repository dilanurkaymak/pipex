#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

void	error_exit(char *msg);
char	*find_path(char *cmd, char **envp);
void	exec_input(int *pipe_end, char **av, char **envp);
void	exec_output(int *pipe_end, char **av, char **envp);

#endif
