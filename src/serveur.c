/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:12:38 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/12 16:10:02 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_check_user_1(int signal, const struct sigaction *act, int *not_use)
{
	static int bit;
	static char user1;
	
	bit = 0;
	(void)not_use;
	if (signal == SIGUSR1)
		user1 |= (bit << 0x01);
}

int	ft_check_user_2(int signal, const struct sigaction *act, int *not_use)
{
	static int bit;
	static char user2;
	
	bit = 0;
	(void)not_use;
	if (signal == SIGUSR2)
		user2 &= ~(bit << 0x01);
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
		signal(SIGUSR1, ft_check_user_1);
		signal(SIGUSR2, ft_check_user_2);
	}
	return (0);
}