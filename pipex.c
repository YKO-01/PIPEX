/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:48:32 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/01/14 13:00:29 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pro(char *file, char *cmd, char **env)
{
	int fd;
  	t_pipex	ppx;
	char	**command;
	char	*err;

	//file_err(0, file);
	fd	= open(file, O_RDONLY);
	if (fd < 0)
		file_err(0, file);
	fd = dup2(fd, 0);
	command = ft_split(cmd, ' ');
	if (ft_strchr(cmd, 34))
	{
		command = ft_split(cmd, 34);
		command = check_cmd(command);
	}
	if (ft_strchr(cmd, 39))
	{
		command = ft_split(cmd, 39);
		command = check_cmd(command);
	}
	if (cmd[0] == '.' && cmd[1] == '/')
	{
		if (access(&(cmd[2]), F_OK) < 0)
			exit(127);
		else if (access(&(cmd[2]), X_OK) < 0)
			exit(126);
		else
			ppx.path = cmd;
	}
	else
	{
		ppx.path = git_path(env);
		ppx.path = cheak_path(*command, ppx.path);
	}
	if (!ppx.path)
	{
		err = ft_strjoin("pipex: ", cmd);
		ft_putstr_fd(ft_strfree(err, ": command not found\n"), 2);
		exit(127);
	}
	execve(ppx.path, command, env);
	exit(126);
}

void	perent_pro(char *cmd, char *file, char **env)
{
	int fd;
  	t_pipex	ppx;
	char 	**command;
	char	*err;

	//file_err(1, file);
	fd	= open(file, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
		file_err(1, file);
	fd = dup2(fd, 1);
	command = ft_split(cmd, ' ');
	if (ft_strchr(cmd, 34))
	{
		command = ft_split(cmd, 34);
		command = check_cmd(command);
	}
	if (ft_strchr(cmd, 39))
	{
		command = ft_split(cmd, 39);
		command = check_cmd(command);
	}
	if (cmd[0] == '.' && cmd[1] == '/')
	{
		if (access(&(cmd[2]), F_OK) < 0)
			exit(127);
		else if (access(&(cmd[2]), X_OK) < 0)
			exit(126);
		else
			ppx.path = cmd;
	}
	else
	{
		ppx.path = git_path(env);
		ppx.path = cheak_path(*command, ppx.path);
	}
	ppx.path = git_path(env);
	ppx.path = cheak_path(*command, ppx.path);
	if (!ppx.path)
	{
		err = ft_strjoin("pipex: ", cmd);
		ft_putstr_fd(ft_strfree(err, ": command not found\n"), 2);
		exit(127);
	}
	execve(ppx.path, command, env);
	exit(126);
}

int main(int ac, char *av[], char **env)
{
//	int ex;
	if (ac < 5)
		return (EXIT_FAILURE);
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
	//	int pid2 = fork();
	//	if (pid2 < -1)
	//		exit(0);
	//	if (pid2 == 0)
	//	{
			dup2(fd[0], 0);
			close(fd[0]);
			close(fd[1]);
			perent_pro(av[3], av[4], env);
			wait(NULL);
	//	}
		// close(fd[0]);
		// close(fd[1]);
		//waitpid(pid, NULL, 0);
		//waitpid(pid2, NULL, 0);
	}
	return 0;
}

