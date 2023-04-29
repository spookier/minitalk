#include "../incs/minitalk.h"


void send_signal(int pid, char c)
{
    int bit;

    bit = 8;
    while (bit--)
    {
        if ((c >> bit) & 0x01)
			kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(500);
    }
}


void create_signal(int pid, char *str)
{
	int i;
	int	length;

	i = 0;
	length = ft_strlen(str);
	length++;
	while (length--)
	{
		send_signal(pid, str[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int pid;

	pid = ft_atoi(argv[1]);
	if(argc != 3 || pid <= 0)
	{
		ft_printf("Invalid parameter count or invalid pID\n");
		return(1);
	}
	else
		create_signal(pid, argv[2]);
	return(0);
}