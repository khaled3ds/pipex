/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 10:42:42 by kadas             #+#    #+#             */
/*   Updated: 2025/11/17 19:06:26 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handleenv(char **env)
{
	if (!env || !*env)
		exit(1);
}

static void	helper(char **cmds, int fd[2], int inout, char **env)
{
	char	*path;

	if (!cmds || !(*cmds))
	{
		close(fd[0]);
		close(fd[1]);
		exit(-1);
	}
	close(fd[0]);
	close(fd[1]);
	path = neededpath(env, cmds[0]);
	if (!path)
	{
		free_all(cmds);
		free(path);
		exit(-1);
	}
	close(inout);
	execve(path, cmds, env);
	perror("execve failed");
	free_all(cmds);
	free(path);
	exit(1);
}

static void	readinfile(char **argv, int fd[2], char **env)
{
	char	**cmds;
	int		infile;
	pid_t	id;

	id = fork();
	if (id == -1)
		exit(write(1, "fork failed", 12));
	if (id == 0)
	{
		infile = open(argv[1], O_RDONLY);
		checkinfile(infile);
		if (dup2(infile, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO)
			== -1)
		{
			close(fd[1]);
			close(fd[0]);
			perror("dup failed");
			exit(1);
		}
		close(infile);
		cmds = ft_split(argv[2], ' ');
		helper(cmds, fd, infile, env);
	}
}

static void	putline(char **argv, int fd[2], char **env, int fda)
{
	char	**cmds;
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("open outfile failed");
		if (fda != -1)
			close(fda);
		exit(1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("dup failed");
		exit(1);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("dup failed");
		exit(1);
	}
	close(outfile);
	cmds = ft_split(argv[3], ' ');
	helper(cmds, fd, outfile, env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	id;

	handleenv(env);
	if (argc != 5)
		return (write(2, "invalid number of arguments\n", 29));
	if (pipe(fd) == -1)
	{
		perror("pipe failed");
		return (1);
	}
	readinfile(argv, fd, env);
	close(fd[1]);
	wait(NULL);
	id = fork();
	if (id == -1)
	{
		perror("fork failed");
		exit(1);
	}
	if (id == 0)
		putline(argv, fd, env, fd[0]);
	wait(NULL);
	close(fd[0]);
	return (0);
}
