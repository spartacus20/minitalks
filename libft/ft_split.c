/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:27:10 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/14 12:14:43 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_elements(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static size_t	get_wlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_mem(size_t i, char **arr)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

static char	**split(char const *s, char c, char **arr, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (s[j] && s[j] == c)
			j++;
		arr[i] = ft_substr(s, j, get_wlen(&s[j], c));
		if (!arr[i])
		{
			free_mem(i, arr);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_elements(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr = split(s, c, arr, words);
	return (arr);
}
