/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:08:56 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/26 16:43:55 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	do_action(int signal, siginfo_t *siginfo, void *context)
{
	(void)signal;
	(void)siginfo;
	(void)context;
	printf("yay\n");
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = do_action;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	write(1, "\x33", 1);
	while (1)
		continue ;
	return (0);
}
