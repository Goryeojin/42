/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:07:58 by rgo               #+#    #+#             */
/*   Updated: 2022/09/10 14:20:16 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base(char c, char *base, int b_len)
{
	int	i;

	i = 0;
	while (i < b_len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_get_b_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (*base == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == 32 \
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	b_len;
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	b_len = ft_get_b_len(base);
	if (b_len <= 1)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && ft_base(str[i], base, b_len) != -1)
	{
		result = (result * b_len) + ft_base(str[i], base, b_len);
		i++;
	}
	return (sign * result);
}
