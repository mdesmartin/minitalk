/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:46:27 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/21 14:05:14 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	a;

	a = 0;
	while (a <= ft_strlen(s))
	{
		if (s[a] == (char)c)
			return (((char *) s) + a);
		a++;
	}
	return (0);
}
