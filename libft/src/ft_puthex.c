/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:56:44 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/12 20:22:35 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthex(unsigned int n, char specifier)
{
	int	rem;
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, specifier);
	rem = n % 16;
	if (rem > 9)
		rem = rem - 10 + specifier - 23;
	else
		rem = rem + '0';
	count += ft_putchar(rem);
	return (count);
}
