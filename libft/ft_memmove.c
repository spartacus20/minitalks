/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:29:33 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/14 12:13:52 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*str_dest;
	const char	*str_src;

	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	str_dest = dest;
	str_src = src;
	if (str_src < str_dest)
	{
		str_dest += n;
		str_src += n;
		while (n-- > 0)
			*--str_dest = *--str_src;
	}
	else
	{
		while (n-- > 0)
			*str_dest++ = *str_src++;
	}
	return (dest);
}
