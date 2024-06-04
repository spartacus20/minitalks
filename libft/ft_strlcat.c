/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:24:22 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/14 13:33:08 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	if (!dst || !src)
		return (0);
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = dest_len;
	if (size == 0 || size <= dest_len)
		return (src_len + size);
	while (i < size - dest_len - 1 && src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dest_len + src_len);
}
