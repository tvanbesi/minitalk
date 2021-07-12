/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:28:47 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/12 15:01:04 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	g_spid = 0;

void
	sig1_handler(int n, siginfo_t *info, void *ucontext)
{
	write(STDOUT, "S1", 2);
	g_spid = info->si_pid;
}

void
	sig2_handler(int n, siginfo_t *info, void *ucontext)
{
	write(STDOUT, "S2", 2);
	g_spid = info->si_pid;
}

int
	main(void)
{
	pid_t				pid;
	struct sigaction	sig1;
	sigset_t			sig1_mask;
	struct sigaction	sig2;
	sigset_t			sig2_mask;

	sigemptyset(&sig1_mask);
	sigemptyset(&sig2_mask);
	sig1.sa_mask = sig1_mask;
	sig2.sa_mask = sig2_mask;
	sig1.sa_flags = SA_SIGINFO;
	sig2.sa_flags = SA_SIGINFO;
	sig1.sa_sigaction = sig1_handler;
	sig2.sa_sigaction = sig2_handler;
	sigaction(SIGUSR1, &sig1, NULL);
	sigaction(SIGUSR2, &sig2, NULL);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	while (1)
	{
		pause();
		kill(g_spid, SIGUSR1);
		g_spid = 0;
	}
	return (0);
}
