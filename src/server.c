/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:08:56 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/28 21:37:59 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	binary_to_dec(char *binary)
{
	int	i;
	int	num;

	i = 7;
	num = 0;
	while (i > 0)
	{
		if (binary[i] == '1')
			num += ft_pow(2, 7 - i);
		i--;
	}
	if (binary[i] == '0')
		num *= -1;
	return (num);
}

void	get_message(int signal, siginfo_t *info, void *context)
{
	static int	count;
	static char	symbol[2];
	static char	binary[9];
	static char	*str;
	static int	flag;

	(void)context;
	if (!flag)
	{
		symbol[1] = '\0';
		binary[8] = '\0';
		str = malloc(sizeof(*str));
		if (!str)
			exit(EXIT_FAILURE);
		*str = '\0';
		flag = 1;
	}
	if (signal == SIGUSR1)
		binary[count] = '1';
	else if (signal == SIGUSR2)
		binary[count] = '0';
	count++;
	if (count == 8)
	{
		symbol[0] = binary_to_dec(binary);
		str = ft_strjoin_free(str, symbol);
		if (symbol[0] == 0)
		{
			ft_printf("%s", str);
			free(str);
			kill(info->si_pid, SIGUSR1);
			usleep(100);
			flag = 0;
		}
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				serv_pid;

	serv_pid = getpid();
	ft_printf("Server PID is %d\n", serv_pid);
	act.sa_sigaction = get_message;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		continue ;
	return (0);
}
