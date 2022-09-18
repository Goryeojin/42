/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:54:40 by rgo               #+#    #+#             */
/*   Updated: 2022/08/29 14:27:50 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_digit(char *buff, int idx, int val, int n)
{
	int	max;

	max = 10 - n;
	if (idx == n)
	{
		if (buff[0] == max + '0')
		{
			write(1, buff, n);
		}
		else
		{
			write(1, buff, n);
			write(1, ", ", 2);
		}
	}
	else
	{
		while (val <= 9)
		{
			buff[idx] = val + '0';
			ft_print_digit(buff, idx + 1, val + 1, n);
			val++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	buff[9];
	int		idx;
	int		val;

	idx = 0;
	val = 0;
	ft_print_digit(buff, idx, val, n);
}
