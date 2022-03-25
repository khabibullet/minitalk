/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_isspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:39:56 by anemesis          #+#    #+#             */
/*   Updated: 2022/03/13 17:14:37 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_strcount(char const *s)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!ft_isspace(*s))
		{
			while (!ft_isspace(*s) && *s)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static int	newstr(char	**spl, const char	*s, size_t	count)
{
	size_t	i;

	*(spl + count) = NULL;
	i = count;
	while (i)
	{
		count = 0;
		while (ft_isspace(*s))
			s++;
		while (!ft_isspace(*(s + count)) && *(s + count) != '\0')
			count++;
		if (*s)
		{
			*spl = (char *)malloc(sizeof(char) * (count + 1));
			if (!*spl)
				return (0);
			ft_strlcpy(*spl, s, count + 1);
		}
		if (!count)
			return (0);
		s = s + count;
		spl++;
		i--;
	}
	return (1);
}

char	**ft_split_isspace(char	const	*s)
{
	char	**spl;
	size_t	count;

	if (!s)
		return (NULL);
	if (*s == '\0')
		count = 0;
	else
		count = ft_strcount(s);
	spl = (char **)malloc(sizeof(char *) * (count + 1));
	if (!spl)
		return (NULL);
	if (!newstr(spl, s, count))
		return (NULL);
	return (spl);
}
