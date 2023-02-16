/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:29:25 by mvogel            #+#    #+#             */
/*   Updated: 2023/02/16 16:07:23 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

// recupere en arg, convertis en bi puis envoi a server pid avec kill ?



int	main(int argc, char **argv)
{	
	pid_t		pid;

	if (argc != 2)
		return (0);

	pid = argv[1];
	// str = convert(argv[2]);
	kill(pid, SIGUSR1);
	// kill(pid, SIGUSR2);
}
