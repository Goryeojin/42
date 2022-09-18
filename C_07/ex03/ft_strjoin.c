/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:02:48 by rgo               #+#    #+#             */
/*   Updated: 2022/09/10 17:29:50 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(dest + i))
		i++;
	while (*src)
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

int	ft_size_cal(int size, char **strs, char *sep)
{
	int	strs_len;
	int	sep_len;
	int	i;

	strs_len = 0;
	sep_len = (ft_strlen1(sep));
	if (size == 1)
		return (ft_strlen1(strs[0]) + 1);
	i = 0;
	while (i < size - 1)
	{
		strs_len += ft_strlen1(strs[i]);
		strs_len += sep_len;
		i++;
	}
	strs_len += ft_strlen1(strs[i]);
	return (strs_len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		i;
	char	*str;

	if (size <= 0)
	{
		str = (char *)malloc(1);
		str[0] = 0;
		return (str);
	}
	total_len = ft_size_cal(size, strs, sep);
	str = (char *)malloc(sizeof(char) * total_len);
	i = 0;
	if (*(str + i) != 0)
		*(str + i) = 0;
	while (i < size - 1)
	{
		str = ft_strcat(str, *(strs + i));
		str = ft_strcat(str, sep);
		i++;
	}
	str = ft_strcat(str, *(strs + i));
	return (str);
}
