#include "pipex.h"

static char	*get_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*build_cmd_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

static char	*search_in_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*full;
	int		i;

	path_env = get_path_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full = build_cmd_path(paths[i], cmd);
		if (full && access(full, X_OK) == 0)
			return (ft_free_split(paths), full);
		free(full);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}

void	parse_cmd(t_cmd *cmd, char *cmd_str, char **envp)
{
	cmd->args = ft_split(cmd_str, ' ');
	if (!cmd->args || !cmd->args[0])
		error_exit("parse");
	if (ft_strchr(cmd->args[0], '/'))
	{
		if (access(cmd->args[0], X_OK) != 0)
			error_exit("command");
		cmd->path = ft_strdup(cmd->args[0]);
	}
	else
	{
		cmd->path = search_in_path(cmd->args[0], envp);
		if (!cmd->path)
			error_exit("command");
	}
}
