/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:12:38 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/04 14:40:40 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_handler(int signal)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		
	}
}
int	main(int ac, char **av)
{
	int pid;

	(void)av;
	if (ac != 1)
	{
		printf("Error\nError signal generation");
	}
	pid = getpid();
	printf("%d\n", pid);
	while(ac == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
	}
	return (0);
}