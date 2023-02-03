/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:16:38 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/03 15:41:16 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**check_cmd(char **command)
{
	char	**cmd;

	cmd = ft_split(command[0], ' ');
	command[0] = ft_substr(cmd[0], 0, ft_strlen(cmd[0]));
	free_2d_array(cmd, 0);
	return (command);
}

int	check_command(char *cmd, char c)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == c && cmd[i + 1] == ' ' && cmd[i + 2] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**split_cmd(char *cmd, char **command, char c)
{
	char	*tmp;
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (cmd[i] && cmd[i] != c)
		i++;
	tmp = ft_substr(cmd, 0, i);
	i++;
	if (cmd[i] == c)
		i++;
	j = ft_strlen(cmd) - i - 1;
	res = ft_substr(cmd, i, j);
	command = (char **)ft_calloc(3, sizeof(char *));
	command[0] = *(ft_split(tmp, ' '));
	command[1] = ft_substr(res, 0, ft_strlen(res));
	return (free(tmp), free(res), command);
}

char	**argument_cmd(char *cmd, char c)
{
	char	**command;
	char	*str;
	int		i;
	int		len;

	command = ft_split(cmd, ' ');
	len = 0;
	i = 0;
	while (command[i])
		len += ft_strlen(command[i++]);
	str = malloc(len + 1);
	i = 0;
	while (command[i])
		str = ft_strfree(str, command[i++]);
	command = ft_split(str, c);
	return (free(str), command);
}

char	**check_quotes(char *cmd, char **command)
{
	if (ft_strchr(cmd, 34))
	{
		if (check_command(cmd, 34) == 0)
		{
			command = split_cmd(cmd, command, 34);
			if (ft_strchr(command[1], 39))
				return (check_cmd(command));
		}
		else
			command = argument_cmd(cmd, '"');
	}
	if (ft_strchr(cmd, 39))
	{
		if (check_command(cmd, 39) == 0)
		{
			command = split_cmd(cmd, command, 39);
			if (ft_strchr(command[1], 34))
				return (check_cmd(command));
		}
		else
			command = argument_cmd(cmd, 39);
	}
	return (command);
}
