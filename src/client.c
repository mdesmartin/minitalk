/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:29:25 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/06 12:47:01 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(unsigned int val, pid_t pid_server, int bit)
{
	while (bit != 0)
	{
		if (val >> bit & 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		bit--;
		usleep(100);
	}
}

void	confirm_reception()
{
	ft_putstr_fd("Message received\n", 1);
}

int	main(int argc, char **argv)
{	
	struct	sigaction 	sign;
	unsigned int		pid_server;
	int					i;
	
	i = 0;
	if (argc != 3)
		return (ft_putstr_fd("Error\nClient need server PID and a string", 2), -1);
	pid_server = ft_atoi(argv[1]);
	if (kill(pid_server, 0) != 0)
		return (ft_putstr_fd("Error\nServer PID is not correct", 2), -1);

	sign.sa_handler = confirm_reception;
	sigaction(SIGUSR1, &sign, NULL);
	send_bit(getpid(), pid_server, 32);

	while (argv[2] != NULL && argv[2][i] != 0)
	{
		send_bit(argv[2][i], pid_server, 8);
		i++;
	}
	send_bit(127, pid_server, 32);
	pause();
	return (0);
}
