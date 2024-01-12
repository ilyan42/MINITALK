/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:35:09 by ilbendib          #+#    #+#             */
/*   Updated: 2024/01/12 13:38:20 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../LIBFT/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct sigaction
{
	void		(*sa_handler) (int);
	void		(*sa_sigaction) (int, siginfo_t *, void *);
	sigset_t	sa_mask;
	int		sa_flags;
	void		(*sa_restorer) (void);
}		t_sigaction;

#endif