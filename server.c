/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:28:47 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/12 18:27:54 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	g_spid = 0;

static void
	interpret_message(int b)
{
	static char	character[8];
	static int	i = 0;
	int			char_n;

	character[i] = b + '0';
	i++;
	if (i == 8)
	{
		char_n = bstoc(character);
		ft_putchar_fd(char_n, STDOUT);
		i = 0;
	}
	return ;
}

void
	sig1_handler(int n, siginfo_t *info, void *ucontext)
{
	interpret_message(0);
	g_spid = info->si_pid;
}

void
	sig2_handler(int n, siginfo_t *info, void *ucontext)
{
	interpret_message(1);
	g_spid = info->si_pid;
}

void
	init_sig(struct sigaction *sig1, struct sigaction *sig2)
{
	sigset_t			sig_mask;

	sigemptyset(&sig_mask);
	sig1->sa_mask = sig_mask;
	sig2->sa_mask = sig_mask;
	sig1->sa_flags = SA_SIGINFO;
	sig2->sa_flags = SA_SIGINFO;
	sig1->sa_sigaction = sig1_handler;
	sig2->sa_sigaction = sig2_handler;
	sigaction(SIGUSR1, sig1, NULL);
	sigaction(SIGUSR2, sig2, NULL);
}

int
	main(void)
{
	pid_t				pid;
	struct sigaction	sig1;
	struct sigaction	sig2;

	init_sig(&sig1, &sig2);
	pid = getpid();
	ft_putnbr_fd(pid, STDOUT);
	write(STDOUT, "\n", 1);
	while (1)
	{
		pause();
		kill(g_spid, SIGUSR1);
		g_spid = 0;
	}
	return (0);
}
