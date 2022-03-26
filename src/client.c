/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:08:06 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/26 19:27:49 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
// #include <stdio.h>

int	main(int argc, char *argv[])
{
	size_t	i;

	(void)argc;
	ft_printf("%s\n", argv[1]);
	i = 0;
	while (i < ft_strlen(argv[1]))
	{
		ft_printf("%i\n", (int)argv[1][i]);
		i++;
	}
	write(1, argv[1], 3);
	// kill(atoi(argv[1]), SIGUSR1);
	return (0);
}
