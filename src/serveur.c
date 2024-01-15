/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:12:38 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/15 14:34:26 by ilyanbendib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void ft_check_signal(int signal, siginfo_t *info, void *note_use)
{
	static int bit;
	static int i;

	(void)info;
	(void)note_use;
	if (signal == SIGUSR1)
	{
		i |= (0x01 << bit);
	}
	bit++;

	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;
	sigset_t			signals;

	pid = getpid();
	sigemptyset(&signals);
	sigaddset(&signals, SIGUSR1);
	sigaddset(&signals, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_mask = signals;
	action.sa_handler = NULL;
	action.sa_sigaction = ft_check_signal;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	printf("PID server -> %d\n", pid);
	while (1)
		pause();
	return (0);
}
