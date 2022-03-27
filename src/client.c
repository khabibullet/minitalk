/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:08:06 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/27 20:17:28 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	get_feedback(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		ft_printf("Message has been successfully sent\n");
}

void	dec_to_binary(int symbol, char *binary)
{
	int	i;
	int	num;

	binary[8] = '\0';
	binary[0] = '1';
	if (symbol < 0)
	{
		binary[0] = '0';
		symbol *= -1;
	}
	i = 1;
	num = 64;
	while (i < 8)
	{
		binary[i] = '0';
		if (symbol >= num)
		{
			binary[i] = '1';
			symbol -= num;
		}
		num /= 2;
		i++;
	}
}

void	send_binary(char *binary, int serv_pid)
{
	int	i;

	i = 0;
	while (binary[i])
	{
		if (binary[i] == '1')
			kill(serv_pid, SIGUSR1);
		else
			kill(serv_pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	fback;
	char				binary[9];
	size_t				i;

	if (argc != 3)
	{
		ft_printf("Invalid input\n");
		return (0);
	}
	fback.sa_sigaction = get_feedback;
	fback.sa_flags = SA_SIGINFO;
	i = 0;
	while (argv[2][i])
	{
		dec_to_binary(argv[2][i], binary);
		send_binary(binary, ft_atoi(argv[1]));
		i++;
	}
	sigaction(SIGUSR1, &fback, NULL);
	return (0);
}
