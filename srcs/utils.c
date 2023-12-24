/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:29:10 by bfaisy            #+#    #+#             */
/*   Updated: 2023/12/14 17:36:56 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	utils2(int *pipe_fd, int file1_fd, char **av, char **ev)
{
	if (close(pipe_fd[0]) == -1)
		perror("close");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		perror("dup2");
	if (close(pipe_fd[1]) == -1)
	{
		perror("close");
		exit (0);
	}
	if (dup2(file1_fd, STDIN_FILENO) == -1)
		exit(0);
	if (close(file1_fd) == -1)
	{
		perror("close");
		exit (0);
	}
	execute_command(av[2], ev);
}

void	end(char **av, t_pid pid, t_fd fd, char **ev)
{
	pid.pid1 = fork();
	if (pid.pid1 == -1)
	{
		perror("fork");
		exit(0);
	}
	if (pid.pid1 == 0)
		utils2(fd.pipe_fd, fd.file1_fd, av, ev);
	pid.pid2 = fork();
	if (pid.pid2 == -1)
	{
		perror("fork");
		exit(0);
	}
	if (pid.pid2 == 0)
		utils(fd.pipe_fd, fd.file2_fd, av, ev);
	close(fd.pipe_fd[0]);
	close(fd.pipe_fd[1]);
	waitpid(pid.pid1, NULL, 0);
	waitpid(pid.pid2, NULL, 0);
}

void	create(t_pid pid, char **av)
{
	char	*str[3];

	pid.pid0 = fork();
	if (pid.pid0 == -1)
	{
		perror("fork");
		exit (0);
	}
	if (pid.pid0 == 0)
	{
		str[0] = "/bin/touch";
		str[1] = av[4];
		str[2] = NULL;
		execve(str[0], str, NULL);
	}
	else
		wait(NULL);
}

void	utils(int *pipe_fd, int file2_fd, char **av, char **ev)
{
	if (close(pipe_fd[1]) == -1)
	{
		perror("close");
		exit(0);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		exit(0);
	if (close(pipe_fd[0]) == -1)
	{
		perror("close");
		exit (0);
	}
	if (dup2(file2_fd, STDOUT_FILENO) == -1)
		exit (0);
	if (close(file2_fd) == -1)
	{
		perror("close");
		exit(0);
	}
	execute_command(av[3], ev);
}

char	*getcmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*c;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		c = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(c, 0) == 0)
			return (c);
		free(c);
		paths++;
	}
	return (NULL);
}
