/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:29:25 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/25 13:09:11 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>

int	g_server_confirm;

void	confirm_reception(int signum)
{
	if (signum == SIGUSR1)
		g_server_confirm = 1;
	if (signum == SIGUSR2)
	{
		ft_putstr_fd("Message received\n", 1);
		exit(0);
	}
}

void	send_bit(unsigned int val, pid_t pid_server, int bit)
{
	int	i;

	i = 0;
	while (i < bit)
	{
		g_server_confirm = 0;
		if (val >> i & 1)
			kill (pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		i++;
		while (!g_server_confirm)
			usleep(1);
	}
}

int	main(int argc, char *argv[])
{	
	struct sigaction	sign;
	pid_t				pid_server;
	int					i;

	sigemptyset(&sign.sa_mask);
	sign.sa_flags = SA_SIGINFO;
	sign.sa_handler = confirm_reception;
	i = 0;
	if (argc != 3)
		return (ft_putstr_fd("Error\nClient need server PID and a string\n", \
		2), 1);
	pid_server = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &sign, NULL);
	sigaction(SIGUSR2, &sign, NULL);
	send_bit(ft_strlen(argv[2]), pid_server, 32);
	while (argv[2] != NULL && argv[2][i] != 0)
		send_bit(argv[2][i++], pid_server, 8);
	send_bit(0, pid_server, 8);
	pause();
	return (0);
}
