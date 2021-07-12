/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:51:57 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/12 14:57:19 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void
	sig1_handler(int n)
{
}

int
	main(int argc, char **argv)
{
	pid_t	pid;

	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sig1_handler);
	if (kill(pid, SIGUSR1) != 0)
		write(STDOUT, strerror(errno), ft_strlen(strerror(errno)));
	pause();
	if (kill(pid, SIGUSR2) != 0)
		write(STDOUT, strerror(errno), ft_strlen(strerror(errno)));
	pause();
	if (kill(pid, SIGUSR2) != 0)
		write(STDOUT, strerror(errno), ft_strlen(strerror(errno)));
	pause();
	if (kill(pid, SIGUSR1) != 0)
		write(STDOUT, strerror(errno), ft_strlen(strerror(errno)));
	pause();
	return (0);
}
