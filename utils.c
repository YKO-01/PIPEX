/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:16:38 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/01/15 14:10:07 by ayakoubi         ###   ########.fr       */
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
	t_pipex	ppx;
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			ppx.path = env[i] + 5;
		}
		// else
		// {
		// 	ft_printf("None\n");
		// 	exit(1);
		// }
	}
	return (ppx.path);
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
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
	}
	while (new_path[++i])
	{
		last_path = ft_strjoin(new_path[i], "/");
		last_path = ft_strfree(last_path, cmd);
		if (access(last_path, F_OK) == 0)
			return (last_path);
	}
	return (NULL);
}

// int check_space(char *str)
// {
//     int i;
//     i = 0;
//     while (str[i] && str[i] != ' ')
//         i++;
//     return (i);

// }

// char	*check_cmd(char	*cmd)
// {
// 	int i;
// 	char	*new;
// 	char	*cmd;
// 	char	*last;
// 	int		j;
// 	i = 0;
// 	j = 0;
	
// 	i = check_space(cmd);
// 	new = ft_substr(cmd, 0, i + 1);
// 	last = ft_substr(cmd, i + 1, ft_strlen(cmd));
// 	cmd = ft_strfree(cmd, last);
// 	return (cmd);
// }

// char	**check_cmd(char **command)
// {
// 	int i;

// 	cmd = ft_split(command[0], ' ');

// 	return (cmd);
// }

char	**check_cmd(char **command, char *path, char **env)
{
	char	**cmd;

	cmd = ft_split(command[0], ' ');
	command[0] = ft_substr(cmd[0], 0, ft_strlen(cmd[0]));
	if (command[1][0] == 39 || command[1][0] == 34)
			execve(path, command, env);
	//command[1] = ft_substr(command[1], 0, ft_strlen(command[1]));
	return (command);
}

void	file_err(int mode, char *file)
{
	if (mode == 0)
	{
		if (access(file, F_OK) < 0)
		{
			ft_printf("pipex: %s: No such file or directory\n",  file);
			exit(1);
		}
		if (access(file, R_OK) < 0)
		{
			ft_printf("pipex: %s: permission denied\n", file);
			exit(1);
		}
	}
	else if (mode == 1)
	{
		if (access(file, W_OK) < 0)
		{
			ft_printf("pipex: %s: permission denied\n", file);
			exit(1);
		}
	}
}

void	check_script(char *cmd, t_pipex ppx, char **env)
{
	int	i;
	i = 0;
	//char	**script;
	if (cmd[i] == '.' && cmd[i + 1] == '/')
	{
		if (access(&(cmd[i+2]), F_OK) < 0)
			exit(1);
		else if (access(&(cmd[i+2]), X_OK) < 0)
			exit(126);
		else
			ppx.path = cmd;
	}
	else
	{
		ppx.path = git_path(env);
		ppx.path = cheak_path(cmd, ppx.path);
	}
}