/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:53:06 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/15 12:14:04 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_check_bit(int pid, char i)
{
	int bit;
	
	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill (pid, SIGUSR1); 
		else
			kill (pid, SIGUSR2);
		usleep(5000);
		bit++;
	}
}

int main(int ac, char **av)
{
	int pid;
	int i = 0;

	if (ac == 3)
	{
		pid = atoi(av[1]);
		printf("PID: %d\n", pid);
		while (av[2][i] != '\0')
		{	
			ft_check_bit(pid, av[2][i]);
			i++;
		}
		ft_check_bit(pid, '\n');
	}
	return (0);
}