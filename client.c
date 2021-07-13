/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:51:57 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/13 11:45:18 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void
	sig1_handler(int n)
{
	(void)n;
	set_received(1);
}

static void
	send_bit(int b, pid_t pid)
{
	if (b == '0')
		kill(pid, SIGUSR1);
	else if (b == '1')
		kill(pid, SIGUSR2);
	while (!get_received())
		usleep(1000);
}

static void
	init_sig(void)
{
	struct sigaction	sig;
	sigset_t			sig_mask;

	sigemptyset(&sig_mask);
	sigaddset(&sig_mask, SIGUSR1);
	sig.sa_mask = sig_mask;
	sig.sa_flags = 0;
	sig.sa_handler = sig1_handler;
	sigaction(SIGUSR1, &sig, NULL);
}

static int
	sanity_check(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	if (kill(ft_atoi(argv[1]), 0) != 0)
		return (0);
	return (1);
}

int
	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	char	*bs;
	int		i;

	if (!sanity_check(argc, argv))
		return (-1);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	init_sig();
	while (*message)
	{
		bs = ctobs(*message);
		if (!bs)
			return (-1);
		i = 0;
		while (i++ < 8)
		{
			send_bit(bs[i - 1], pid);
			set_received(0);
		}
		free(bs);
		message++;
	}
	return (0);
}
