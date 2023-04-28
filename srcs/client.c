#include "../incs/minitalk.h"

void send_signal(int pid)
{
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
}

int main(int argc, char **argv)
{
	int pid;
	pid = ft_atoi(argv[1]);
	if(argc != 3 || pid <= 0)
	{
		ft_printf("Invalid parameter count / Invalid PID\n");
		return(1);
	}
	while (1)
	{
		send_signal(pid);
		usleep(200);
	}
}