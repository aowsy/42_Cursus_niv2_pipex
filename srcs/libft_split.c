/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:59:52 by mdelforg          #+#    #+#             */
/*   Updated: 2022/03/11 16:00:41 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_tab(char **tab, size_t i)
{
	i++;
	while (i)
	{
		i--;
		free (tab[i]);
	}
	free (tab);
	return ;
}

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || i == ft_strlen(s) || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

void	split_str(char const *s, char c, char **tab, size_t i)
{
	size_t	j;
	size_t	word_len;

	j = 0;
	while (i < count_word(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		word_len = 0;
		while (s[j] && s[j] != c)
		{
			word_len++;
			j++;
		}
		tab[i] = ft_substr(&s[0], j - word_len, word_len);
		if (!tab[i])
		{
			free_tab(tab, i);
			return ;
		}
		i++;
	}
	tab[i] = 0;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	split_str(s, c, tab, 0);
	return (tab);
}
