#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h> // fork ,execve
# include <stdlib.h> // malloc ile free
# include <stdio.h> // perror
# include <sys/types.h> //pid_t ayrı bir struct tipiymiş onu da kullanıcaz
# include <sys/wait.h> //waitpid

typedef struct s_pipex
{
	char *cmd;//kullanıcıdan gelen komut ls -l gibi
	char **cmd_args;
	char *cmd_path;
	char **envp;
} t_pipex;

#endif