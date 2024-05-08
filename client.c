/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:55:35 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/08 16:37:35 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(100);
		bit++;
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
			server_pid = to_num(argv[1]);
		else if (server_pid <= 0 || !is_digits(argv[1]))
		{
			ft_printf("Enter a valid PID\n");
			return(1);
		}
		while (argv[2][i])
		{
			send_signal(argv[2][i], server_pid);
			i++;
		}
	}
	else
		ft_printf("Usage: ./client [PID] [MESSAGE]\n");
	return (0);
}
