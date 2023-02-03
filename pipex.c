/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:48:32 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/03 21:35:21 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	my_exit(char *ptr, int ex, char *arg)
{
	if (!arg)
		ft_printf("%s\n", ptr);
	else
		ft_printf("%s%s\n", ptr, arg);
	exit(ex);
}

void	child_pro(char *file, char *cmd, char **env)
{
	int		fd;
	t_pipex	ppx;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		file_err(0, file);
	if (dup2(fd, 0) < 0)
		exit(1);
	close(fd);
	ppx.command = ft_split(cmd, ' ');
	ppx.command = check_quotes(cmd, ppx.command);
	ppx.path = check_script(cmd, ppx.path, env, ppx.command);
	if (!ppx.path)
	{
		free_2d_array(ppx.command, 0);
		free(ppx.path);
		my_exit("pipex: command not found: ", 127, cmd);
	}
	if (execve(ppx.path, ppx.command, env) < 0)
	{
		free_2d_array(ppx.command, 0);
		free(ppx.path);
		exit(1);
	}
	exit(126);
}

void	perent_pro(char *cmd, char *file, char **env)
{
	int		fd;
	t_pipex	ppx;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		file_err(1, file);
	if (dup2(fd, 1) < 0)
		exit(1);
	close(fd);
	ppx.command = ft_split(cmd, ' ');
	ppx.command = check_quotes(cmd, ppx.command);
	ppx.path = check_script(cmd, ppx.path, env, ppx.command);
	if (!ppx.path)
	{
		free_2d_array(ppx.command, 0);
		free(ppx.path);
		my_exit("pipex: command not found: ", 127, cmd);
	}
	if (execve(ppx.path, ppx.command, env) < 0)
	{
		free_2d_array(ppx.command, 0);
		free(ppx.path);
		exit(1);
	}
	exit(126);
}

int	main(int ac, char *av[], char *env[])
{
	int	fd[2];
	int	pid;

	if (ac != 5)
		return (EXIT_FAILURE);
	if (pipe(fd) < 0)
		my_exit("an error in creating pipe", 1, NULL);
	pid = fork();
	if (pid < 0)
		my_exit("an error in creating processe", 1, NULL);
	if (pid == 0)
	{
		if (dup2(fd[1], 1) < 0)
			exit(1);
		close(fd[0]);
		close(fd[1]);
		child_pro(av[1], av[2], env);
	}
	if (dup2(fd[0], 0) < 0)
		exit(1);
	close(fd[0]);
	close(fd[1]);
	perent_pro(av[3], av[4], env);
	return (0);
}
