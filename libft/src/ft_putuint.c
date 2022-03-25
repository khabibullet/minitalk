/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:03:20 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/12 20:22:55 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putuint(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putuint(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}
