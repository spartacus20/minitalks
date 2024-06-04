/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:58:16 by jotomas-          #+#    #+#             */
/*   Updated: 2024/01/05 11:33:30 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_char(char c)
{
	int	count;

	count = 0;
	ft_putchar(c);
	count++;
	return (count);
}
