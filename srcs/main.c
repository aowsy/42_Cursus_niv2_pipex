/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:48:53 by mdelforg          #+#    #+#             */
/*   Updated: 2022/03/22 09:19:45 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_parent_process(t_data *data, char **env)
{
	close(data->p_fd[1]);
	ft_path_init(data->cmd_tab2[0], data);
	dup2(data->fd2, STDOUT_FILENO);
	dup2(data->p_fd[0], STDIN_FILENO);
	close(data->fd2);
	execve(data->path, data->cmd_tab2, env);
	perror("Command couldn't execute");
	return ;
}

void	ft_child_process(t_data *data, char **env)
{
	close(data->p_fd[0]);
	ft_path_init(data->cmd_tab1[0], data);
	dup2(data->fd1, STDIN_FILENO);
	dup2(data->p_fd[1], STDOUT_FILENO);
	close(data->fd1);
	execve(data->path, data->cmd_tab1, env);
	perror("Command couldn't execute");
	return ;
}

int	ft_pipex(t_data *data, char **env)
{
	int	wstatus;

	if (pipe(data->p_fd) == -1)
		ft_error(data, "Pipe error");
	data->pid1 = fork();
	if (data->pid1 < 0)
		ft_error(data, "Fork error");
	if (!data->pid1)
		ft_child_process(data, env);
	else
	{
		data->pid2 = fork();
		if (data->pid2 < 0)
			ft_error(data, "Fork error");
		if (!data->pid2)
			ft_parent_process(data, env);
	}
	close(data->p_fd[0]);
	close(data->p_fd[1]);
	waitpid(data->pid2, &wstatus, 0);
	return (WEXITSTATUS(wstatus));
}

void	ft_data_init(t_data *data, char **av)
{
	data->path = NULL;
	data->cmd_tab1 = ft_split(av[2], ' ');
	data->cmd_tab2 = ft_split(av[3], ' ');
	if (!data->cmd_tab1 || !data->cmd_tab2)
		ft_error(data, "Malloc error");
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		exitval;

	if (ac == 5)
	{
		ft_data_init(&data, av);
		data.fd1 = open(av[1], O_RDONLY);
		if (data.fd1 < 0)
			ft_error(&data, "Wrong file descriptor");
		data.fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (data.fd2 < 0)
			ft_error(&data, "Wrong file descriptor");
		exitval = ft_pipex(&data, envp);
		ft_free_data(&data);
		return (exitval);
	}
	else
		perror("Invalid argument");
	return (1);
}
