/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 05:14:42 by bfaisy            #+#    #+#             */
/*   Updated: 2023/12/14 17:38:57 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_split(char **tab);
void	execute_command(char *str, char **ev);

int	main(int ac, char **av, char **ev)
{
	t_fd	fd;
	t_pid	pid;

	if (ac != 5)
		return (0);
	pid.pid0 = 0;
	if (access(av[4], F_OK) == -1)
		create(pid, av);
	fd.file1_fd = open(av[1], O_RDWR);
	fd.file2_fd = open(av[4], O_RDWR | O_TRUNC);
	if (fd.file2_fd == -1 || fd.file1_fd == -1)
	{
		perror("open");
		exit(0);
	}
	if (pipe(fd.pipe_fd) == -1)
	{
		perror("pipe");
		exit(0);
	}
	end(av, pid, fd, ev);
}

void	execute_command(char *str, char **ev)
{
	char	**first_command;

	first_command = ft_split(str, ' ');
	if (!first_command)
	{
		perror("malloc fail");
		exit(0);
	}
	if (execve(getcmd(ft_split(get_path(ev), ':'), first_command[0]),
			first_command, ev) == -1)
		perror("Erro     d");
	free_split(first_command);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_path(char *envp[])
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}
