/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:01:44 by rgo               #+#    #+#             */
/*   Updated: 2022/09/11 11:04:07 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*str;

	src_len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!(str))
		return (0);
	str = ft_strcpy(str, src);
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*re;
	int			i;

	re = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (re == 0)
		return (0);
	i = 0;
	while (i < ac && av[i] != 0)
	{
		re[i].size = ft_strlen(av[i]);
		re[i].str = av[i];
		re[i].copy = ft_strdup(av[i]);
		i++;
	}
	re[i].size = 0;
	re[i].str = 0;
	re[i].copy = 0;
	return (re);
}
