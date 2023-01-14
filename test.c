#include "pipex.h"

char	*ft_strfree(char *s1, char *s2)
{
	char	*tmp;
	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

int check_space(char *str)
{
    int i;
    i = 0;
    while (str[i] && str[i] != ' ')
        i++;
    return (i);

}

char	**check_cmd(char **command)
{
	int i;
	char	*new;
	char	**cmd;
    char **nnn;
	i = 0;
    int j;
    j = 0;

	// while (*command[i] && *command[i] != ' ')
	// 	i++;
    i = check_space((command[0])); 
    ft_putnbr_fd(i, 2);
	new = ft_substr(*command, 0, i + 1);
    ft_putstr_fd(new, 1);
	cmd = ft_split(new, ' ');
    while (*command)
    {
        j += ft_strlen(*(command++));
    }

    new = ft_substr(*command, i + 1, j);
	*cmd = ft_strfree(*cmd, new);
    //ft_putnbr_fd(j, 2);
    // while (*command){
	//     *nnn += ft_substr(*command, 5, ft_strlen(*command));
    //     *(command++);
    // }
    // // ft_putstr_fd(*nnn, 2);
	// *cmd = ft_strfree(*cmd, *nnn);
    // while (*cmd)
    //     ft_putstr_fd(*cmd++, 2);
	return (cmd);
}

char	**check_cmd(char **command)
{
	int i;
	int j;
	char	*new;
	char	**cmd;
	char	*last;
	i = 0;
	j = 0;

	// i = check_space((command[0]));
	// ft_putnbr_fd(i, 2); 
	// new = ft_substr(*command, 0, i + 1);
	// ft_putstr_fd(new, 2);
	// while (*command)
    // {
    //     j += ft_strlen(*(command++));
    // }
	// ft_putnbr_fd(j, 2); 
	cmd = ft_split(command[0], ' ');
	// while (*cmd)
	// 	ft_putstr_fd(*cmd++, 2);
	//ft_putstr_fd(*cmd, 2);
	last = ft_substr(cmd[0], 0, ft_strlen(cmd[0]));
	new = ft_substr(command[1], 0, ft_strlen(command[1]));
	//ft_putstr_fd(new, 2);
	last = ft_strfree(last, new);
	//ft_putstr_fd(last, 2);
	//*cmd = ft_strfree(*cmd, last);
	// while(*cmd)
	// 	ft_putstr_fd(*cmd++, 2);
	return (cmd);
}

int main()
{
    char **cmd;
    char *command[] = {"grep ", "hello ", "word"};
        // ft_putstr_fd(command[0], 2);
        // ft_putstr_fd(command[1], 2);
    cmd = check_cmd(command);
    // while (*cmd)
    //     ft_putstr_fd(*cmd++, 2);
    return 0;
}