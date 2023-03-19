/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:56:43 by mehdidesmar       #+#    #+#             */
/*   Updated: 2023/03/19 23:11:51 by mehdidesmar      ###   ########lyon.fr   */
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
		ft_printf("bon pour realloc");
		new_ptr = malloc(size);
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
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
