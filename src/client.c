/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:53:06 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/15 15:08:38 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

// void ft_check_output(int signal)
// {
// 	if (signal == SIGUSR1)
// 	{
		
// 	}
// }
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
		usleep(250);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	pid = ft_atoi(argv[1]);
	i = -1;
	// signal(SIGUSR1, ft_check_output);
	// signal(SIGUSR2, ft_check_output);
	if (argc == 3)
	{
		while (argv[2][++i])
			ft_check_bit(pid, argv[2][i]);
		ft_check_bit(pid, '\n');
		ft_check_bit(pid, 0);
		// while (1)
		// 	pause();
	}
}