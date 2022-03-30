/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:08:56 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/30 12:25:11 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	g_response[2] = {0};

void	get_message(int signal, siginfo_t *info, void *context)
{
	static int	num;
	static char	symb;
	static int	flag;

	(void)context;
	if (!flag)
	{
		num = 128;
		flag = 1;
		symb = 0;
	}
	if (signal == SIGUSR1)
			symb += num;
	num = num >> 1;
	if (!num)
	{
		ft_putchar(symb);
		flag = 0;
	}
	g_response[1] = info->si_pid;
	g_response[0] = 1;
}

int	main(void)
{
	struct sigaction	act;
	pid_t				serv_pid;

	serv_pid = getpid();
	ft_printf("Server PID is %d\n", serv_pid);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = get_message;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		while (!g_response[0])
			continue ;
		g_response[0] = 0;
		kill(g_response[1], SIGUSR1);
	}
	return (0);
}
