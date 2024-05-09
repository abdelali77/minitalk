/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:56:49 by abmahfou          #+#    #+#             */
/*   Updated: 2024/05/09 15:50:40 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>

int		to_num(char *str);
bool	is_digits(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif