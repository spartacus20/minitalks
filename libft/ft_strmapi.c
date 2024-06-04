/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:41:40 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/10 12:40:03 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

static char	*str_new(size_t n)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (n + 1));
	if (!arr)
		return (NULL);
	return (arr);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))

{
	char	*arr;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	arr = str_new(len);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = (*f)(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
