/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:24:46 by rgo               #+#    #+#             */
/*   Updated: 2022/09/07 11:22:52 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putboard(int board[])
{
	int		idx;
	int		tmp;

	idx = 0;
	while (idx < 10)
	{
		tmp = board[idx] + '0';
		write(1, &tmp, 1);
		idx++;
	}
	write(1, "\n", 1);
}

int	promising(int idx, int board[])
{
	int		i;
	int		tmp;

	i = 0;
	while (i < idx)
	{
		tmp = board[idx] - board[i];
		if (tmp < 0)
			tmp *= -1;
		if (board[idx] == board[i] || idx - i == tmp)
			return (0);
		i++;
	}
	return (1);
}

void	ft_queens(int idx, int *cnt, int board[])
{
	int		i;

	i = 0;
	if (idx == 10)
	{
		*cnt += 1;
		ft_putboard(board);
		return ;
	}
	while (i < 10)
	{
		board[idx] = i;
		if (promising(idx, board))
			ft_queens(idx + 1, cnt, board);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		cnt;
	int		idx;
	int		board[10];

	cnt = 0;
	idx = 0;
	while (idx < 10)
		board[idx++] = 0;
	ft_queens(0, &cnt, board);
	return (cnt);
}
