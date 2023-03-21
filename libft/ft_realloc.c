/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:56:43 by mehdidesmar       #+#    #+#             */
/*   Updated: 2023/03/21 14:00:14 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	old_size;

	new_ptr = NULL;
	old_size = 0;
	if (ptr == NULL)
	{
		new_ptr = ft_calloc(1, size);
		return (new_ptr);
	}
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	old_size = ft_strlen(ptr);
	if (size <= old_size)
		return (ptr);
	new_ptr = ft_calloc(1, size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
