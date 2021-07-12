/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:51:57 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/12 16:51:28 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void
	sig1_handler(int n)
{
}

static void
	send_bit(int b, pid_t pid)
{
	if (b == '0')
		kill(pid, SIGUSR1);
	else if (b == '1')
		kill(pid, SIGUSR2);
}

int
	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	char	*bs;
	int		i;

	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sig1_handler);
	message = argv[2];
	while (*message)
	{
		bs = ctobs(*message);
		if (!bs)
			return (-1);
		i = 0;
		while (i++ < 8)
		{
			send_bit(bs[i - 1], pid);
			pause();
		}
		free(bs);
		message++;
	}
	return (0);
}
