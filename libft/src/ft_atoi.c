/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:59:38 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/13 19:26:34 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char	*str)
{
	long	sum;
	long	lsum;
	int		sign;

	sum = 0;
	sign = 1;
	while (((9 <= *str) && (*str <= 13)) || (*str == ' '))
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (ft_isdigit(*str))
	{
		lsum = sum;
		sum = 10 * sum + *str - '0';
		if (sum < lsum)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		str++;
	}
	return (sum * sign);
}

int	ft_atoi_limited(const char	*str)
{
	long	sum;
	long	lsum;
	int		sign;

	if (!str)
		exit_error();
	sum = 0;
	sign = 1;
	while (((9 <= *str) && (*str <= 13)) || (*str == ' '))
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (ft_isdigit(*str))
	{
		lsum = sum;
		sum = 10 * sum + *str - '0';
		if (sum < lsum)
			exit_error();
		str++;
	}
	if ((sum * sign < -2147483648) || (sum * sign > 2147483647))
		exit_error();
	return (sum * sign);
}
