/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:29:25 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/18 12:58:47 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>

void	send_bit(unsigned int val, pid_t pid_server, int bit)
{
	while (bit != 0)
	{
		if (val % 2 == 0)
			kill(pid_server, SIGUSR1);
		if (val % 2 == 1)
			kill (pid_server, SIGUSR2);
		val /= 2;
		bit--;
		usleep(100);
	}
}

void	confirm_reception(int sigusr)
{
	(void) sigusr;
	ft_putstr_fd("Message received\n", 1);
	exit(0);
}

int	main(int argc, char *argv[])
{	
	struct sigaction	sign;
	unsigned int		pid_server;
	int					i;

	i = 0;
	sign.sa_handler = confirm_reception;
	sigemptyset(&sign.sa_mask);
	sign.sa_flags = SA_SIGINFO;

	if (argc != 3)
		return (ft_putstr_fd("Error\nClient need server PID and a string\n", \
		2), -1);
	pid_server = ft_atoi(argv[1]);
	if (kill(pid_server, 0) != 0)
		return (ft_putstr_fd("Error\nServer PID is not correct\n", 2), -1);
	sigaction(SIGUSR1, &sign, NULL);
	send_bit(getpid(), pid_server, 32);
	while (argv[2] != NULL && argv[2][i] != 0)
		send_bit(argv[2][i++], pid_server, 8);
	send_bit(0, pid_server, 8);
	pause();
	return (0);
}
