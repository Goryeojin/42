/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:25:51 by sanghule          #+#    #+#             */
/*   Updated: 2022/08/29 17:13:47 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

char	char_to_put(int row, int col, int n_row, int n_col)
{
	int			put_char_row;
	int			put_char_col;
	static char	norm[3][3] = {{"/*\\"}, {"* *"}, {"\\*/"}};

	if (row == 0)
		put_char_row = 0;
	else if (row == n_row - 1)
		put_char_row = 2;
	else
		put_char_row = 1;
	if (col == 0)
		put_char_col = 0;
	else if (col == n_col - 1)
		put_char_col = 2;
	else
		put_char_col = 1;
	return (norm[put_char_row][put_char_col]);
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			ft_putchar(char_to_put(row, col, y, x));
			col++;
		}
		row++;
		ft_putchar('\n');
	}
}
