/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 08:32:55 by aborda            #+#    #+#             */
/*   Updated: 2026/01/15 11:24:27 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	process_signal(int bit, int pid)
{
	if (bit == 0)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
	else
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

static	void process_bit(char c, int pid)
{
	int	j;
	int	bit;

	j = 7;
	while (j >= 0)
	{
		bit = (c >> j) & 1;
		process_signal(bit, pid);
		j--;
	}

}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			process_bit(av[2][i], pid);
			i++;
		}
		process_bit('\n', pid);
		return (0);
	}
	ft_putstr_fd("Error: wrong arguments (PID + string)\n", 2);
	return (1);
}
