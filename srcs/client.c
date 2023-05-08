/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:13:33 by acostin           #+#    #+#             */
/*   Updated: 2023/05/08 14:10:53 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	send_signal(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit) & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(850);
	}
}

void	recieve_signal(int signal)
{
	(void)signal;
	ft_printf("Signal from client received.\n");
	exit(0);
}

void	send_client_pid(int pid, int client_pid)
{
	int	bit;

	bit = 32;
	while (bit--)
	{
		if ((client_pid >> bit) & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (bit == 0)
		{
			while (1)
			{
				signal(SIGUSR1, recieve_signal);
				pause();
			}
		}
		usleep(650);
	}
}

void	create_signal(int pid, char *str)
{
	int	i;
	int	length;
	int	client_pid;

	client_pid = getpid();
	i = 0;
	length = ft_strlen(str);
	length++;
	while (length--)
	{
		send_signal(pid, str[i]);
		i++;
	}
	send_client_pid(pid, client_pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Invalid parameters or invalid PID\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid >= 4194304)
	{
		ft_printf("Invalid parameters or invalid PID\n");
		return (1);
	}
	create_signal(pid, argv[2]);
	return (0);
}
