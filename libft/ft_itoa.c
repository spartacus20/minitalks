/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:09:13 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/14 12:13:36 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static long long	number_size(long long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*str_new(size_t n)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (n + 1));
	if (!arr)
		return (NULL);
	return (arr);
}

char	*ft_itoa(int n)
{
	char			*arr;
	int				len;
	unsigned int	num;

	num = 0;
	len = number_size(n);
	arr = str_new(len);
	if (n < 0)
	{
		arr[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		arr[0] = '0';
	arr[len] = '\0';
	while (num != 0)
	{
		arr[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (arr);
}
