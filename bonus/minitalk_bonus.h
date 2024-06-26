/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:33:25 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/28 11:19:51 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>

int		to_num(char *str);
bool	is_digits(char *str);
int		ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);

#endif