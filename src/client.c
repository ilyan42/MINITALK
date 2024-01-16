/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:53:06 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/15 18:58:51 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int validation_check;

void	ft_check_output(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("Message sent and received.\n");
		exit(EXIT_SUCCESS);
	}
	else if (signal == SIGUSR1)
		validation_check = 1;
}
void	ft_check_bit(int pid, unsigned char c)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		validation_check = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (validation_check != 1)
			usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	pid = ft_atoi(argv[1]);
	i = -1;
	signal(SIGUSR1, ft_check_output);
	signal(SIGUSR2, ft_check_output);
	if (argc == 3)
	{
		while (argv[2][++i])
			ft_check_bit(pid, argv[2][i]);
		ft_check_bit(pid, '\n');
		ft_check_bit(pid, 0);
		while (1)
			pause();
	}
}

