/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_script.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:24:20 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/01 21:24:53 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_script(char *cmd, char *path, char **env, char **command)
{
	char	**script;

	if (cmd[0] == '.' && cmd[1] == '/')
	{
		script = ft_split(cmd, ' ');
		if (access(&(script[0][2]), F_OK) < 0)
		{
			ft_printf("pipex: no such file or directory: %s\n", cmd);
			free(command);
			exit(127);
		}
		if (access(&(script[0][2]), X_OK) < 0)
		{
			ft_printf("pipex: permission denied: %s\n", cmd);
			free(command);
			exit(126);
		}
		path = cheak_path(script[0], path);
	}
	else
		path = get_path(env);
		path = cheak_path(*command, path);
	return (path);
}
