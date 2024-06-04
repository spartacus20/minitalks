/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:21:14 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/13 14:19:24 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	join = (char *)malloc(s1len + s2len + 1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1len + 1);
	ft_strlcat(join, s2, (s1len + s2len) + 1);
	return (join);
}
