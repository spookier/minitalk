/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:13:08 by acostin           #+#    #+#             */
/*   Updated: 2023/05/08 14:10:22 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

void	receive_client_pid(int signal, int *flag)
{
	static int	client_pid;
	static int	count_pid;

	client_pid = client_pid << 1;
	if (signal == SIGUSR1)
		client_pid++;
	count_pid++;
	if (count_pid == 32)
	{
		kill(client_pid, SIGUSR1);
		*flag = 0;
		client_pid = 0;
		count_pid = 0;
	}
}

void	signal_handle(int signal)
{
	static int	flag;
	static int	count;
	static int	byte;

	if (flag)
		receive_client_pid(signal, &flag);
	else
	{
		byte = byte << 1;
		if (signal == SIGUSR1)
			byte++;
		count++;
		if (count == 8)
		{
			ft_printf("%c", byte);
			if (byte == '\0')
				flag++;
			count = 0;
			byte = 0x0;
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Invalid parameter\n");
		return (1);
	}
	pid = -1;
	pid = getpid();
	if (pid == -1 || pid <= 0 || pid >= 4194304)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, signal_handle);
		signal(SIGUSR2, signal_handle);
		pause();
	}
	return (0);
}
