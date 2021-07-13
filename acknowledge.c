/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acknowledge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:31:44 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/13 11:44:40 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int
	*received(void)
{
	static int	received = 0;

	return (&received);
}

void
	set_received(int val)
{
	*(received()) = val;
}

int
	get_received(void)
{
	return (*(received()));
}
