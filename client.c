/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:55:35 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/04 21:19:59 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(unsigned char c, int pid)
{
	unsigned char	bit;
	int				i;

	i = 8;
	while (i > 0)
	{
		bit = c >> i;
		if (bit % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = 0;
	server_pid = 0;
	if (argc == 3)
	{
		if (is_digits(argv[1]))
			server_pid = ft_atoi(argv[1]);
		else if (server_pid <= 0 || !is_digits(argv[1]))
			ft_printf("Enter a valid PID\n");
		while (argv[2][i])
		{
			send_signal(argv[2][i], server_pid);
			i++;
		}
	}
	else
		ft_printf("Usage: ./client [PID] [MESSAGE]\n");
}
