/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:00:35 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/18 16:22:10 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <stdbool.h>

typedef struct s_bit
{
	unsigned char	value;
	int				i;
}	t_bit;

void	get_bit(int signum, siginfo_t *info, void *contex)
{
	pid_t 			pid_client;
	static t_bit	bit;

	(void) contex;
	pid_client = info->si_pid;
	if (signum == SIGUSR2)
		bit.value += 1 << bit.i;
	bit.i++;
	if (bit.i == 8)
	{
		bit.i = 0;
		write(1, &(bit.value), 1);
		if (bit.value == 0)
			kill(pid_client, SIGUSR2);
		bit.value = 0;
	}
	kill(pid_client, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sign;

	sigemptyset(&sign.sa_mask);
	sign.sa_flags = SA_SIGINFO;	
	sign.sa_sigaction = get_bit;

	if (argc != 1 && argv[0][0] != '\0')
		return (ft_putstr_fd("Error\nServer does not take parameters\n", 2), -1);
	ft_printf("Server PID is : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sign, NULL);
		sigaction(SIGUSR2, &sign, NULL);
	}
	return (0);
}
