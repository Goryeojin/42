/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:05:46 by rgo               #+#    #+#             */
/*   Updated: 2022/09/14 13:09:39 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return ;
	}
	else if (nb >= 0)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

int	ft_test(int op, int num2)
{
	if (num2 == 0)
	{
		if (op == 2)
		{
			write(1, "Stop : division by zero\n", 24);
			return (-1);
		}
		if (op == 4)
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (-1);
		}
	}
	return (0);
}

void	ft_do_op(int num1, int op, int num2)
{
	int		(*cal[5])(int, int);

	cal[0] = add;
	cal[1] = sub;
	cal[2] = div;
	cal[3] = mul;
	cal[4] = mod;
	if (ft_test(op, num2) == -1)
		return ;
	else
	{
		ft_putnbr(cal[op](num1, num2));
		ft_putchar('\n');
	}
}
