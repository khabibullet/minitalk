#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	do_action(void)
{
	printf("yay\n");
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = do_action;
	sigaction(SUGUSR1, &act, NULL);
	while (1)
		continue ;
	return (0);
}
