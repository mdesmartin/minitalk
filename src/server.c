/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:00:35 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/06 21:42:03 by mehdidesmar      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <stdbool.h>

typedef struct s_bit
{
	unsigned char	value;
	int				i;
	bool			status;
	int				pid_client;
}	t_bit;

void	client_pid(t_bit *bit)
{
	bit->status = true;
	bit->value = 0;
	bit->i = 0;
}

void	write_msg(t_bit *bit)
{
	write(1, &(bit->value), 1);
	if (bit->value == 0)
	{
		kill(bit->pid_client, SIGUSR1);
		bit->status = false;
		bit->pid_client = 0;
	}
	bit->value = 0;
	bit->i = 0;
}

void	get_bit(int sigusr)
{
	static t_bit	bit;
	bool			bin;
	
	if (sigusr == SIGUSR1)
		bin = 0;
	if (sigusr == SIGUSR2)
		bin = 1;
	bit.value += bin << bit.i;
	if (bit.status == false)
		bit.pid_client += bin << bit.i;
	bit.i++;
	if (bit.status == false && bit.i == 32)
		client_pid(&bit);
	if (bit.status == true && bit.i == 8)
		write_msg(&bit);
}

int	main(int argc, char **argv)
{
	struct sigaction	sign;

	sign.sa_handler = get_bit;

	if (argc != 1 && argv[0][0] != '\0')
		return (ft_putstr_fd("Error\nServer does not take parameters", 2), -1);
	ft_printf("Server PID is : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sign, NULL);
		sigaction(SIGUSR2, &sign, NULL);
	}
	return (0);
}
