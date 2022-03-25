/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:42:51 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/12 20:22:50 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr(char	*s)
{
	int	count;

	count = 0;
	if (s != NULL)
	{
		while (*s)
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	else
		count += ft_putstr("(null)");
	return (count);
}
