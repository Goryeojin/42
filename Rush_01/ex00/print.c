/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:19:37 by eunwolee          #+#    #+#             */
/*   Updated: 2022/09/04 20:49:22 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void)
{
	write (1, "error\n", 6);
	return ;
}

void	print_no_answer(void)
{
	write (1, "no answer\n", 10);
}

void	print_board(int **board)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			c = board[x][y] + '0';
			write (1, &c, 1);
			y++;
		}
		write (1, "\n", 1);
		x++;
	}
	return ;
}
