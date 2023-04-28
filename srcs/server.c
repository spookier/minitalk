#include "../incs/minitalk.h"

void sig_handle(int signum)
{
  printf("Inside handler function\n");
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
		signal(SIGUSR1, sig_handle);
	}
	return(0);
}
