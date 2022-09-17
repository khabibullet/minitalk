/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:08:06 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/31 18:06:38 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

int	g_flag = 0;

void	get_response(int signal)
{
	(void)signal;
	g_flag = 1;
}

void	send_str(char *str, int serv_pid)
{
	size_t	i;
	int		num;

	i = 0;
	while (str[i])
	{
		num = 128;
		while (num)
		{
			if (num & str[i])
				kill(serv_pid, SIGUSR1);
			else
				kill(serv_pid, SIGUSR2);
			while (!g_flag)
				continue ;
			g_flag = 0;
			num = num >> 1;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	fback;
	pid_t				serv_pid;

	if (argc != 3)
	{
		ft_printf("Invalid input\n");
		return (0);
	}
	serv_pid = ft_atoi(argv[1]);
	fback.sa_handler = get_response;
	sigaction(SIGUSR1, &fback, NULL);
	send_str(argv[2], serv_pid);
	return (0);
}
