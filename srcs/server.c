#include "../incs/minitalk.h"

void signal_handle(int signal)
{
	static int count;
	static int byte;

	byte = byte << 1;
	if(signal == SIGUSR1)
		byte |= 1;
	else if(signal == SIGUSR2)
		byte |= 0;
	count++;
	if(count == 8)
	{
		ft_printf("%c", byte);
		count = 0;
		byte = 0x0;
	}
}

int main(void)
{
	int pid;

	pid = -1;
	pid = getpid();
	if (pid == -1 || (pid <= 0 && pid >= 4194304))
	{
		ft_printf("PID Error\n");
		return(1);
	}
	ft_printf("%d\n", pid);
	while(1)
	{
		signal(SIGUSR1, signal_handle);
		signal(SIGUSR2, signal_handle);
		pause();
	}
	return(0);
}
