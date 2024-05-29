/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:45:48 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/28 11:18:37 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	is_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

int	to_num(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res < 100)
	{
		ft_printf("Enter a valid PID\n");
		exit(1);
	}
	else
		return (res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = '\0';
		i++;
	}
}
