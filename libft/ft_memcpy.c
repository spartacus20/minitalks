/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:07:38 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/10 18:16:56 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*str_dest;
	const char	*str_src;

	if ((!dest && !src) || n == 0)
		return (dest);
	str_dest = dest;
	str_src = src;
	i = 0;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (dest);
}
