/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:56:05 by mehdidesmar       #+#    #+#             */
/*   Updated: 2023/03/06 11:24:49 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
#include "../libft/libft.h"

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_bit
{
	unsigned char	value;
	int				i;
	bool			status;
	int				pid_client;
}	t_bit;

#endif