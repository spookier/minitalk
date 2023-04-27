#include "../incs/minitalk.h"

int main(void)
{
	int pid;

	pid = -1;
	pid = getpid();
	if(pid == -1)
	{
		return(0);
	}

	while (1)
	{

	}
}
