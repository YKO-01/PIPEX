/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:45:54 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/01/15 14:10:20 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_pipex
{
    char    *path;
}   t_pipex;


char	*ft_strfree(char *s1, char *s2);
char	*git_path(char	**env);
char	**split_path(char *path);
char	*cheak_path(char *cmd, char *path);
char	**check_cmd(char **command, char *path, char **env);
void	file_err(int mode, char *file);
void	child_pro(char *file, char *cmd, char **env);
void	perent_pro(char *cmd, char *file, char **env);
void	check_script(char *cmd, t_pipex ppx, char **env);

# endif

