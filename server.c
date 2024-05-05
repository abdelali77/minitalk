/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:56:09 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/04 21:28:41 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("0\n");
	else if (sig == SIGUSR1)
		ft_printf("1\n");
}

int	main(void)
{
	ft_printf("Server PID : %d\n", getpid());
	struct sigaction sa;
	sa.sa_handler = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pause();
	return (0);
}
