/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:57:04 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/13 11:58:34 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int
	*spid(void)
{
	static int	spid = 0;

	return (&spid);
}

void
	set_spid(int val)
{
	*(spid()) = val;
}

int
	get_spid(void)
{
	return (*(spid()));
}
