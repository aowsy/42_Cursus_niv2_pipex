/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:58:30 by mdelforg          #+#    #+#             */
/*   Updated: 2022/03/21 17:11:04 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_path_check(char **path)
{
	if (!access(path[0], F_OK))
		return (path[0]);
	if (!access(path[1], F_OK))
		return (path[1]);
	if (!access(path[2], F_OK))
		return (path[2]);
	if (!access(path[3], F_OK))
		return (path[3]);
	if (!access(path[4], F_OK))
		return (path[4]);
	if (!access(path[5], F_OK))
		return (path[5]);
	return (NULL);
}

void	ft_path_init(char *cmd, t_data *data)
{
	int		i;
	char	*path[6];

	path[0] = ft_strjoin("/usr/local/bin/", cmd);
	path[1] = ft_strjoin("/usr/bin/", cmd);
	path[2] = ft_strjoin("/bin/", cmd);
	path[3] = ft_strjoin("/usr/sbin/", cmd);
	path[4] = ft_strjoin("/sbin/", cmd);
	path[5] = ft_strjoin("/usr/local/munki/", cmd);
	i = 0;
	while (i < 6)
	{
		if (!path[i])
		{
			ft_free_path(path);
			ft_error(data, "Malloc error");
		}
		i++;
	}
	data->path = ft_substr(ft_path_check(path), 0,
			ft_strlen(ft_path_check(path)));
	ft_free_path(path);
	return ;
}
