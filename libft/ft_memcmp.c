/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:44:31 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/21 14:06:30 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*u;
	const unsigned char	*d;

	u = s1;
	d = s2;
	while (n)
	{
		if (*u != *d)
			return (*u - *d);
		n--;
		u++;
		d++;
	}
	if (n)
		return (*u - *d);
	return (0);
}
