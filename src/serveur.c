/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:12:38 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/15 12:21:07 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void ft_check_signal(int sig)
{
	static int bit;
	static int i;

	if (sig == SIGUSR1)
	{
		i |= (0x01 << bit);
	}
	bit++;

	if (bit == 8) {
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int main(int ac, char **av)
{
	(void)av;
	struct sigaction sa;
	sa.sa_handler = ft_check_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	int pid = getpid();
	printf("%d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		printf("Error configuring signal manager for SIGUSR1\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		printf("Error configuring signal manager for SIGUSR2\n");
		exit(EXIT_FAILURE);
	}
	while (ac == 1)
	{
		pause();
	}
	return 0;
}
