/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 08:32:55 by aborda            #+#    #+#             */
/*   Updated: 2026/02/09 17:25:04 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	process_signal(int bit, int pid)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("Error: signal failed\n", 2);
			exit(1);
		}
		usleep(800);
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("Error: signal failed\n", 2);
			exit(1);
		}
		usleep(800);
	}
}

static void	process_bit(char c, int pid)
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
		if (pid <= 0)
		{
			ft_putstr_fd("Error: invalid PID\n", 2);
			return (1);
		}
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
