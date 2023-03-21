/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:23:01 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/21 14:04:45 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*rc;
	char		*st;

	rc = src;
	st = dst;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		dst = ft_memcpy(st, rc, len);
		return (dst);
	}
	else
	{
		st = dst + len - 1;
		rc = src + len - 1 ;
		while (len)
		{
			*st = *rc;
			st--;
			rc--;
			len--;
		}
		return (dst);
	}
}
