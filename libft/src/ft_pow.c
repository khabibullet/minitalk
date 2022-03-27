/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:45:31 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/27 16:48:58 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_pow(int base, int degr)
{
	int	pow;

	pow = 1;
	while (degr > 0)
	{
		pow *= base;
		degr--;
	}
	return (pow);
}
