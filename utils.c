/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:16:38 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/01/08 11:49:21 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

char	*ft_strfree(char *s1, char *s2)
{
	char	*tmp;
	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

char	*git_path(char	**env)
{
	char	*path;
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = env[i] + 5;
		}
	}
	return (path);
}

char	**split_path(char *path)
{
	char	**new_path;
	int		i;

	new_path = ft_split(path, ':');
	i = -1;
	return (new_path);
}

char *cheak_path(char *cmd, char *path)
{
	char **new_path;
	new_path = split_path(path);
	char *last_path;
	int i;
	i = -1;
	while (new_path[++i])
	{
		last_path = ft_strjoin(new_path[i], "/");
		last_path = ft_strfree(last_path, cmd);
		if (access(last_path, F_OK) == 0)
			return (last_path);
	}
	return (NULL);
}

char	**check_cmd(char **command)
{
	int i;
	char	*new;
	char	**cmd;
	i = 0;

	while (*command && *command[i] != ' ')
		i++;
	new = ft_substr(*command, 0, i + 1);
	cmd = ft_split(new, ' ');
	new = ft_substr(*command, i + 1, ft_strlen(*command));
	*cmd = ft_strfree(*cmd, new);
	int j;
	j = 0;
	while (cmd[j])
		printf("command == > %s", cmd[j++]);
	return (cmd);
}

void	file_err(int mode, char *file)
{
	if (mode == 0)
	{
		if (access(file, F_OK) < 0)
		{
			ft_putstr_fd(ft_strjoin("zsh: no such file or directory: ", file), 2);
			exit(1);
		}
		if (access(file, R_OK) < 0)
		{
			ft_putstr_fd(ft_strjoin("zsh: permission denied: ", file), 2);
			exit(0);
		}
	}
	if (mode == 1)
	{
		if (access(file, W_OK) < 0)
		{
			ft_putstr_fd(ft_strjoin("zsh: permission denied: ", file), 2);
			exit(1);
		}
	}
}
