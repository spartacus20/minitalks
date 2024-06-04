/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:33:05 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/13 14:26:42 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!rptr)
		return (NULL);
	while (s1[j] != '\0' && ft_strchr(set, s1[j]) != NULL)
		j++;
	while (s1[j] != '\0')
	{
		rptr[i] = s1[j];
		i++;
		j++;
	}
	while (i > 0 && ft_strchr(set, rptr[i - 1]) != NULL)
		i--;
	rptr[i] = '\0';
	return (rptr);
}
