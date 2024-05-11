/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:33:09 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/11 11:30:41 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	client_signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
	{
		ft_printf("acknowledgement recieved !!\n");
	}
}

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
	struct sigaction	sa;
	int					server_pid;
	int					i;

	sa.sa_sigaction = &client_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	server_pid = 0;
	if (argc == 3)
	{
		if (is_digits(argv[1]))
			server_pid = to_num(argv[1]);
		else
		{
			ft_printf("Enter a valid PID\n");
			return (1);
		}
		while (argv[2][i])
			send_signal(argv[2][i++], server_pid);
	}
	else
		ft_printf("Usage: ./client [PID] [MESSAGE]\n");
	return (0);
}
