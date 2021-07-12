/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <tvanbesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:20:39 by tvanbesi          #+#    #+#             */
/*   Updated: 2021/07/12 16:35:45 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char
	*ctobs(int n)
{
	char	*bs;
	int		i;

	bs = malloc(8);
	if (!bs)
		return (NULL);
	i = 8;
	while (i-- > 0)
	{
		bs[i] = n % 2 + '0';
		n /= 2;
	}
	return (bs);
}

static int
	pow2(int n)
{
	int	r;

	r = 2;
	if (n == 0)
		return (1);
	while (--n > 0)
		r *= 2;
	return (r);
}

int
	bstoc(const char bs[8])
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	while (i++ < 8)
		r += pow2(8 - i) * (bs[i - 1] - '0');
	return (r);
}
