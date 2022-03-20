/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:12:05 by mdelforg          #+#    #+#             */
/*   Updated: 2022/03/20 10:53:13 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_data(t_data *data)
{
	int	i;

	free(data->path);
	i = 0;
	while (data->cmd_tab1[i])
	{
		free(data->cmd_tab1[i]);
		i++;
	}
	free(data->cmd_tab1);
	i = 0;
	while (data->cmd_tab2[i])
	{
		free(data->cmd_tab2[i]);
		i++;
	}
	free(data->cmd_tab2);
	close(data->fd1);
	close(data->fd2);
	return ;
}

void	ft_free_path(char **path)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(path[i]);
		i++;
	}
	return ;
}

void	ft_error(t_data *data, char *msg)
{
	ft_free_data(data);
	perror(msg);
	exit(EXIT_FAILURE);
}
