/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:13:48 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/15 17:02:22 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	char const	*arr;

	arr = NULL;
	while (*str)
	{
		if (*str == (char)c)
			arr = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return ((char *)arr);
}
