/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:48:32 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/01/08 11:50:59 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pro(char *file, char *cmd, char **env)
{
	int fd;
  	char	*path;
	char	**command;

	fd	= open(file, O_RDONLY);
	if (fd < 0)
		file_err(0, file);
	fd = dup2(fd, 0);
	if (ft_strchr(cmd, 39))
	{
		command = ft_split(cmd, 39);
		command = check_cmd(command);
	}
	else
		command = ft_split(cmd, ' ');	path = git_path(env);
	path = cheak_path(*command, path);
	if (!path)
	{
		ft_putstr_fd(ft_strjoin("zsh: command not found: ", cmd), 2);
		exit(127);
	}
	execve(path, command, env);
	exit(126);
}

void	perent_pro(char *cmd, char *file, char **env)
{
	int fd;
  	char	*path;
	char 	**command;

	fd	= open(file, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
		file_err(1, file);
	fd = dup2(fd, 1);
	if (ft_strchr(cmd, 39))
	{
		command = ft_split(cmd, 39);
		command = check_cmd(command);
	}
	else
		command = ft_split(cmd, ' ');
	path = git_path(env);
	path = cheak_path(*command, path);
	if (!path)
	{
		ft_putstr_fd(ft_strjoin("zsh: command not found: ", cmd), 2);
		exit(127);
	}
	execve(path, command, env);
	exit(126);
}

int main(int ac, char *av[], char **env)
{
	if (ac == 5)
	{
		int fd[2];
		if (pipe(fd) < 0)
		{
			ft_putstr_fd("an error in creating pipe\n", 2);
			exit(1);
		}
		int pid = fork();
		if (pid < 0)
		{
			ft_putstr_fd("an error in creating processe\n", 2);
			exit(1);
		}
		if (pid == 0)
		{
			dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			child_pro(av[1], av[2], env);
		}
		int pid2 = fork();
		if (pid2 < -1)
			exit(1);
		if (pid2 == 0)
		{
			dup2(fd[0], 0);
			close(fd[0]);
			close(fd[1]);
			perent_pro(av[3], av[4], env);
		}
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (1);
}

