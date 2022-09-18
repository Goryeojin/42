/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:30:03 by rgo               #+#    #+#             */
/*   Updated: 2022/09/13 14:01:08 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	ft_find_op(char *str)
{
	const char	*list = "+-/*%";
	int			i;

	i = 0;
	while (list[i])
	{
		if (str[0] == list[i] && str[1] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	int	op;
	int	num1;
	int	num2;

	if (argc == 4)
	{
		op = ft_find_op(argv[2]);
		if (op == -1)
		{
			write(1, "0\n", 2);
			return (0);
		}
		num1 = ft_atoi(argv[1]);
		num2 = ft_atoi(argv[3]);
		ft_do_op(num1, op, num2);
	}
	return (0);
}
