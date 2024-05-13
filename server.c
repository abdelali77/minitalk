/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:56:09 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/13 12:07:21 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int		bit;
	static int		character;
	static pid_t	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		bit = 0;
		character = 0;
	}
	pid = info->si_pid;
	if (sig == SIGUSR1)
		character |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", character);
		character = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
