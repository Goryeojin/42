/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:59:45 by sanghule          #+#    #+#             */
/*   Updated: 2022/08/30 09:38:15 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);
void		normal_case(int col);
void		special_case(int col);

void	rush(int x, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0 || i == y - 1)
		{
			special_case(x);
		}
		else
		{
			normal_case(x);
		}
		i++;
	}
}

void	normal_case(int col)
{
	int	k;

	k = 0;
	while (k < col)
	{
		if (k == 0 || k == col - 1)
		{
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
		}
		k++;
	}
	ft_putchar('\n');
}

void	special_case(int col)
{
	int	j;

	j = 0;
	while (j < col)
	{
		if (j == 0 || j == col - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		j++;
	}
	ft_putchar('\n');
}
