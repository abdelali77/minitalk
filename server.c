/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:56:09 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/06 18:24:15 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	static int	bit_index;
	static unsigned char	c;

	c |= (sig == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", c);
		bit_index = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("Server PID : %d\n", getpid());
	struct sigaction sa;
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pause();
	return (0);
}
