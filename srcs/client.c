/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 08:32:55 by aborda            #+#    #+#             */
/*   Updated: 2026/01/15 08:38:02 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		while (av)
		{

		}
		return (0);
	}

	ft_putstr_fd("Le client doit recevoir 2 paramètres (server PID & string)", 2);
	return (1);


}
