/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:56:30 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/01/12 13:21:28 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>





// int main(int ac, char **av, char **env)
// {
	
// }


/*
int main(int ac, char *av[])
{
	int fd[2];
	if (pipe(fd) == -1)
		printf("an error ocurred with openiong the pipe\n");
	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		//printf("input a number : ");
		//scanf("%d", &x);
		x = atoi(av[1]);
		write (fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("Got from child process %d", y);
	}
	return (0);
}*/
/*
int main()
{
	if (mkfifo("myfifo", 0777) == -1)
	{
		if (errno != EEXIST)
		{
			printf("could not create fifo file\n");
			return 1;
		}
	}
	int fd = open("myfifo", O_WRONLY);
	int x = 97;
	if (write(fd, &x, sizeof(x)) == -1)
		return 2;
	close(fd);
	return (0);
}
*/
/*
int main()
{
	int p1[2];
	int p2[2];
	if (pipe(p1) == -1 )
		return 0;
	if (pipe(p2) == -1)
		return 0;
	int pid = fork();
	if (pid == -1) 
		return 0;
	if (pid == 0)
	{
		close(p2[1]);
		close(p1[0]);
		int x;
		if (read(p2[0], &x, sizeof(x)) == -1)
			return 0;
		printf("received x == > %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return 0;
		printf("wrote x === > %d\n", x);
		close(p2[0]);
		close(p1[1]);
	}
	else
	{
		close(p2[0]);
		close(p1[1]);
		int y;
		srand(time(NULL));
		y = rand() % 10;
		if (write(p2[1], &y, sizeof(y)) == -1)
			return 0;
		printf("wrote y === >%d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)
			return 0;
		printf("result == %d\n", y);
		wait(NULL);
		close(p2[1]);
		close(p1[0]);
	}
	return 0;
}*/

// int main(int argc, char **argv, char **env) {
//  	(void) argc;
//    	(void) argv;	
// 	char	*path;
// 	int i = -1;

// 	while (env[++i])
// 	{
// 		if (strncmp(env[i], "PATH", 4) == 0)
// 		{
// 			path = env[i] + 5;
// 			printf("%s\n", path);
// 		}
// 	}

// }
