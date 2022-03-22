/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:49:11 by mdelforg          #+#    #+#             */
/*   Updated: 2022/03/20 13:49:31 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	int		fd1;
	int		fd2;
	int		pid1;
	int		pid2;
	int		p_fd[2];
	char	*path;
	char	**cmd_tab1;
	char	**cmd_tab2;
}	t_data;

//	Utils
void	ft_free_data(t_data *data);
void	ft_free_path(char **path);
void	ft_path_init(char *cmd, t_data *data);
void	ft_error(t_data *data, char *msg);

//	Libft
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif
