/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:45:54 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/03 15:38:21 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

# define PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"

typedef struct s_pipex
{
	char	*path;
	char	**command;
}	t_pipex;

void	child_pro(char *file, char *cmd, char **env);
void	perent_pro(char *cmd, char *file, char **env);
void	file_err(int mode, char *file);
void	my_exit(char *ptr, int ex, char *arg);
char	*ft_strfree(char *s1, char *s2);
char	*get_path(char	**env);
char	**split_path(char *path);
char	*cheak_path(char *cmd, char *path);
char	**check_cmd(char **command);
int		check_command(char *cmd, char c);
char	**split_cmd(char *cmd, char **command, char c);
char	**argument_cmd(char *cmd, char c);
char	**check_quotes(char *cmd, char **command);
char	*check_script(char *cmd, char *path, char **env, char **command);
void	free_2d_array(char **ar, int start);

#endif
