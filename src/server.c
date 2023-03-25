/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:00:35 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/25 13:09:21 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <stdbool.h>

typedef struct s_bit
{
	char			*message;
	unsigned char	char_value;
	pid_t			pid_client;
	unsigned int	message_size;
	int				i;
	int				j;
	bool			alloc;
}	t_bit;

void	get_message(t_bit *bit)
{
	bit->i = 0;
	bit->message[bit->j] = bit->char_value;
	bit->j++;
	if (bit->char_value == 0)
	{
		ft_printf("%s", bit->message);
		free(bit->message);
		bit->message = NULL;
		bit->j = 0;
		bit->alloc = false;
		kill(bit->pid_client, SIGUSR2);
	}
	bit->char_value = 0;
}

void	alloc_message(t_bit *bit)
{
	bit->i = 0;
	bit->message = ft_calloc(bit->message_size + 1, sizeof(char));
	if (!bit->message)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		exit(1);
	}
	bit->alloc = true;
	bit->char_value = 0;
}

void	get_bit(int signum, siginfo_t *info, void *contex)
{
	static t_bit	bit;

	(void) contex;
	bit.pid_client = info->si_pid;
	if (signum == SIGUSR2)
	{
		if (bit.alloc == true)
			bit.char_value += 1 << bit.i;
		else
			bit.message_size += 1 << bit.i;
	}
	bit.i++;
	if (bit.i == 8 && bit.alloc == true)
		get_message(&bit);
	else if (bit.i == 32 && bit.alloc == false)
		alloc_message(&bit);
	kill(bit.pid_client, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sign;

	(void) argv;
	sigemptyset(&sign.sa_mask);
	sign.sa_flags = SA_SIGINFO;
	sign.sa_sigaction = get_bit;
	if (argc != 1)
		return (ft_putstr_fd("Error\nServer does not take parameters\n", 2), -1);
	ft_printf("Server PID is : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sign, NULL);
		sigaction(SIGUSR2, &sign, NULL);
	}
	return (0);
}
