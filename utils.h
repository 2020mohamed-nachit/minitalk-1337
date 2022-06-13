/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:20:13 by mnachit           #+#    #+#             */
/*   Updated: 2022/04/09 22:20:21 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

struct s_utils
{
	int	i;
	int	pid;
}t_utils;

void	ft_putnbr(unsigned int nb);
int		ft_atoi(const char *str);

#endif
