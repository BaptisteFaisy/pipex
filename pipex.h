/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:07:15 by bfaisy            #+#    #+#             */
/*   Updated: 2023/12/14 17:38:52 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <assert.h>

typedef struct s_pid
{
	pid_t	pid0;
	pid_t	pid1;
	pid_t	pid2;
}	t_pid;

typedef struct s_fd
{
	int		file1_fd;
	int		file2_fd;
	int		pipe_fd[2];
}	t_fd;

void	utils2(int *pipe_fd, int file1_fd, char **av, char **ev);
void	execute_command(char *str, char **ev);
void	end(char **av, t_pid pid, t_fd fd, char **ev);
void	utils(int *pipe_fd, int file2_fd, char **av, char **ev);
void	create(t_pid pid, char **av);
char	*get_path(char *envp[]);
char	*getcmd(char **paths, char *cmd);

#endif