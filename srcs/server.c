#include "../incs/minitalk.h"

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
	printf("%d\n", pid);
	while (1)
	{
		//listen for client
	}
}
