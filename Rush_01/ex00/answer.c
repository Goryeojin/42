/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:24:49 by eunwolee          #+#    #+#             */
/*   Updated: 2022/09/04 16:10:23 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_up(int **board, int *input)
{
	int	x;
	int	y;
	int	count;
	int	before;

	y = 0;
	while (y < 4)
	{
		x = 0;
		count = 0;
		before = 0;
		while (x < 4)
		{
			if (board[x][y] > before)
			{
				before = board[x][y];
				count++;
			}
			x++;
		}
		if (count != input[y])
			return (0);
		y++;
	}
	return (1);
}

int	check_down(int **board, int *input)
{
	int	x;
	int	y;
	int	count;
	int	before;

	y = 0;
	while (y < 4)
	{
		x = 3;
		count = 0;
		before = 0;
		while (x >= 0)
		{
			if (board[x][y] > before)
			{
				before = board[x][y];
				count++;
			}
			x--;
		}
		if (count != input[y + 4])
			return (0);
		y++;
	}
	return (1);
}

int	check_left(int **board, int *input)
{
	int	x;
	int	y;
	int	count;
	int	before;

	x = 0;
	while (x < 4)
	{
		y = 0;
		count = 0;
		before = 0;
		while (y < 4)
		{
			if (board[x][y] > before)
			{
				before = board[x][y];
				count++;
			}
			y++;
		}
		if (count != input[x + 8])
			return (0);
		x++;
	}
	return (1);
}

int	check_right(int **board, int *input)
{
	int	x;
	int	y;
	int	count;
	int	before;

	x = 0;
	while (x < 4)
	{
		y = 3;
		count = 0;
		before = 0;
		while (y >= 0)
		{
			if (board[x][y] > before)
			{
				before = board[x][y];
				count++;
			}
			y--;
		}
		if (count != input[x + 12])
			return (0);
		x++;
	}
	return (1);
}

int	check_answer(int **board, int *input)
{
	int	up;
	int	down;
	int	left;
	int	right;

	up = check_up(board, input);
	down = check_down(board, input);
	left = check_left(board, input);
	right = check_right(board, input);
	if (up && down && left && right)
		return (1);
	return (0);
}
