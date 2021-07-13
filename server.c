/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:28:47 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/13 12:02:47 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	sig_server_handler(int n, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	set_spid(info->si_pid);
	if (n == SIGUSR1)
		set_sig_flag(FLAG1);
	else if (n == SIGUSR2)
		set_sig_flag(FLAG2);
}

void
	init_sig(struct sigaction *sig1, struct sigaction *sig2)
{
	sigset_t			sig_mask;

	sigemptyset(&sig_mask);
	sigaddset(&sig_mask, SIGUSR1);
	sigaddset(&sig_mask, SIGUSR2);
	sig1->sa_mask = sig_mask;
	sig2->sa_mask = sig_mask;
	sig1->sa_flags = SA_SIGINFO;
	sig2->sa_flags = SA_SIGINFO;
	sig1->sa_sigaction = sig_server_handler;
	sig2->sa_sigaction = sig_server_handler;
	sigaction(SIGUSR1, sig1, NULL);
	sigaction(SIGUSR2, sig2, NULL);
}

int
	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sig1;
	struct sigaction	sig2;

	if (argc != 1)
		return (-1);
	(void)argv;
	init_sig(&sig1, &sig2);
	pid = getpid();
	ft_putnbr_fd(pid, STDOUT);
	write(STDOUT, "\n", 1);
	while (1)
	{
		pause();
		interpret_message(get_sig_flag() - 1);
		set_sig_flag(0);
		kill(get_spid(), SIGUSR1);
	}
	return (0);
}
