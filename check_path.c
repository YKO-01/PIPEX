/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:50:50 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/03 21:27:19 by ayakoubi         ###   ########.fr       */
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

char	*get_path(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			return (env[i] + 5);
		}
	}
	return (PATH);
}

char	**split_path(char *path)
{
	char	**new_path;

	new_path = ft_split(path, ':');
	return (new_path);
}

char	*cheak_path(char *cmd, char *path)
{
	char	**new_path;
	char	*last_path;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
	}
	new_path = split_path(path);
	i = -1;
	while (new_path[++i])
	{
		last_path = ft_strjoin(new_path[i], "/");
		last_path = ft_strfree(last_path, cmd);
		if (access(last_path, F_OK) == 0)
			return (free_2d_array(new_path, 0), last_path);
		free(last_path);
	}
	return (free_2d_array(new_path, 0), NULL);
}

void	file_err(int mode, char *file)
{
	if (mode == 0)
	{
		if (access(file, F_OK) < 0)
		{
			ft_printf("pipex: no such file or directory: %s\n", file);
			exit(1);
		}
		if (access(file, R_OK) < 0)
		{
			ft_printf("pipex: permission denied: %s\n", file);
			exit(1);
		}
	}
	else if (mode == 1)
	{
		if (access(file, W_OK) < 0)
		{
			ft_printf("pipex: permission denied: %s\n", file);
			exit(1);
		}
	}
}
