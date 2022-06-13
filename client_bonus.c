/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:18:56 by mnachit           #+#    #+#             */
/*   Updated: 2022/04/09 22:19:06 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sending(char c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		kill (pid, SIGUSR1 + bit);
		usleep (800);
		i--;
	}
}

void	ft_handler(int sig)
{
	(void) sig;
	write(1, "successfully send", 18);
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, ft_handler);
	t_utils.i = 0;
	if (ac != 3)
	{
		write (1, "Usage: ./client [server PID] [string to send]\n", 47);
		exit(1);
	}
	t_utils.pid = ft_atoi(av[1]);
	if (t_utils.pid < 1)
	{
		write(1, "Bad pid \n", 10);
		exit(1);
	}
	while (av[2][t_utils.i])
		sending(av[2][t_utils.i++], t_utils.pid);
	sending('\0', t_utils.pid);
	return (0);
}
