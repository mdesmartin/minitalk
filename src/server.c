/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:00:35 by mvogel            #+#    #+#             */
/*   Updated: 2023/03/18 17:59:40 by mvogel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <stdbool.h>

typedef struct s_bit
{
	char			*message;
	unsigned char	value;
	int				i;
	int				j;
	int				buff_size;
}	t_bit;


//get a bit and add it at [i] in str message, and when buff is full calloc 1x more space
// void	get_message(t_bit *bit)
// {
// 	char	*tmp;

// 	if (!bit->message)
// 	{
// 		bit->message = ft_calloc(1024, sizeof(char));
// 		bit->buff_size = 1;
// 	}
// 	if (bit->j >= (1024 * bit->buff_size))
// 	{
// 		bit->buff_size += 1;
// 		tmp = ft_calloc(1024 * bit->buff_size, sizeof(char));
// 		bit->message = ft_strjoin(bit->message, tmp);
// 		free(tmp);
// 	}
// 	bit->message[bit->j] = bit->value;
// 	bit->j++;
// }
//malloc(): corrupted top size

void	get_message(t_bit *bit)
{
	char	*tmp;

	if (!bit->message)
	{
		bit->message = ft_calloc(1024, sizeof(char));
		bit->buff_size = 1;
	}
	if (bit->j >= (1024 * bit->buff_size))
	{
		bit->buff_size++;
		tmp = ft_calloc(1024, sizeof(char));
		bit->message = ft_strjoin(bit->message, tmp);
		free(tmp);
	}
	bit->message[bit->j] = bit->value;
	bit->j++;
}


void	get_bit(int signum, siginfo_t *info, void *contex)
{
	pid_t			pid_client;
	static t_bit	bit;

	(void) contex;
	pid_client = info->si_pid;
	if (signum == SIGUSR2)
		bit.value += 1 << bit.i;
	bit.i++;
	if (bit.i == 8)
	{
		bit.i = 0;
		get_message(&bit);
		// write(1, &(bit.value), 1);
		if (bit.value == 0)
		{
			ft_printf("%s", bit.message);
			free(bit.message);
			bit.message = NULL;
			kill(pid_client, SIGUSR2);
		}
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
