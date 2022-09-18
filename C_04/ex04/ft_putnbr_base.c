/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:07:44 by rgo               #+#    #+#             */
/*   Updated: 2022/09/05 20:48:31 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long long nb, int b_len, char *base)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < b_len)
	{
		ft_putchar(base[nb % b_len]);
		return ;
	}
	else if (nb >= b_len)
	{
		ft_putnbr(nb / b_len, b_len, base);
		ft_putchar(base[nb % b_len]);
	}
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
		if (base[i] == '+' || base[i] == '-')
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	b_len;

	b_len = ft_get_b_len(base);
	if (b_len <= 1)
		return ;
	ft_putnbr(nbr, b_len, base);
}
