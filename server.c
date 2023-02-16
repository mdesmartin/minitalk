/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:00:35 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/16 16:12:23 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int	main()
{	
	sigset_t	*set;
	struct sigaction oldact;
	struct sigaction act;

	act = printf("Yes");
	sigemptyset(set);
	// sigaddset(set, int);
	sigaction(SIGUSR1, act, oldact);
}


// renvoi getpid la premiere fois qyon le lance puis ensuite traduis ce auil recois et lafiche