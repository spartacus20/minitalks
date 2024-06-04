/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:05:59 by jotomas-          #+#    #+#             */
/*   Updated: 2024/02/09 14:56:12 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <sys/types.h>

void	bits_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char const *argv[])
{
	pid_t	pid;

	(void)argv;
	pid = getpid();
	if (argc != 1)
	{
		ft_printf("Error: wrong format.\n");
		exit(1);
	}
	ft_printf("SERVER PID = %d\n\n", pid);
	ft_printf("Waiting for message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, bits_handler);
		signal(SIGUSR2, bits_handler);
		pause();
	}
	return (0);
}
