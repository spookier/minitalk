#include "../incs/minitalk.h"


void send_back_signal()
{
	
}


void signal_handle(int signal)
{
	static int count;
	static int count_pid;
	static int	flag;
	static int byte;
	static int client_pid;

	if (flag)
	{
		client_pid = client_pid << 1;
		if(signal == SIGUSR1)
			client_pid |= 1;
		count_pid++;
		if(count_pid == 32)
		{
			kill(client_pid, SIGUSR1);
			flag = 0 ;
			client_pid = 0;
			count_pid = 0;
		}
	}
	else
	{
		byte = byte << 1;
		if(signal == SIGUSR1)
			byte |= 1;
		count++;
		if(count == 8)
		{
			ft_printf("%c", byte);
			if(byte == '\0')
				flag++;
			count = 0;
			byte = 0x0;
		}
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
