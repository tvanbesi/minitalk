/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:37 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/13 11:59:02 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int
	*sig_flag(void)
{
	static int	sig_flag = 0;

	return (&sig_flag);
}

void
	set_sig_flag(int val)
{
	*(sig_flag()) = val;
}

int
	get_sig_flag(void)
{
	return (*(sig_flag()));
}
