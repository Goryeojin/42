/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:03:12 by rgo               #+#    #+#             */
/*   Updated: 2022/09/11 14:16:47 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_get_b_len(char *base);
int	ft_atoi_base(char *str, char *base, int b_len);
int	ft_malloc_size(int nb, int b_len);

char	*ft_itoa_base(int nb, char *base, int b_len)
{
	char	*str;
	char	*tmp;
	int		str_len;
	int		i;

	i = 0;
	str_len = ft_malloc_size(nb, b_len);
	str = (char *)malloc(sizeof(char) * str_len + 1);
	tmp = str;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	i = str_len - 1;
	while (nb)
	{
		str[i] = base[nb % b_len];
		nb /= b_len;
		i--;
	}
	str[str_len] = 0;
	return (tmp);
}

int	ft_malloc_size(int nb, int b_len)
{
	int	s_len;

	s_len = 0;
	if (nb < 0)
	{
		s_len++;
		nb *= -1;
	}
	while (nb)
	{
		nb /= b_len;
		s_len++;
	}
	return (s_len);
}

char	*ft_zero(char *base)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = base[0];
	str[1] = 0;
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		bf_len;
	int		bt_len;
	int		nb;

	bf_len = ft_get_b_len(base_from);
	bt_len = ft_get_b_len(base_to);
	if (bf_len <= 1 || bt_len <= 1)
		return (0);
	nb = ft_atoi_base(nbr, base_from, bf_len);
	if (nb == 0)
		str = ft_zero(base_to);
	else
		str = ft_itoa_base(nb, base_to, bt_len);
	return (str);
}
