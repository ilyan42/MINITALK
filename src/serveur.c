/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:12:38 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/15 16:57:10 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void ft_check_signal(int signal, siginfo_t *info, void *note_use)
{
	static int bit;
	static int i;

	(void)note_use;
	if (signal == SIGUSR1)
	{
		i |= (0x01 << bit);
	}
	if (bit == 8)
	{
		if (i == 0)
			kill (info->si_pid, SIGUSR2);
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
	bit++;
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
	ft_printf("PID server -> %d\n", pid);
	while (1)
		pause();
	return (0);
}
