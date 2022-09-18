/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:51:21 by eunwolee          #+#    #+#             */
/*   Updated: 2022/09/05 11:29:14 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_answer(int **board, int *input);

int	check_board_row(int **board)
{
	int	x;
	int	y;
	int	check[4];

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
			check[y++] = 0;
		y = 0;
		while (y < 4)
		{
			if (board[x][y] > 0)
				check[board[x][y] - 1]++;
			y++;
		}
		y = 0;
		while (y < 4)
			if (check[y++] > 1)
				return (0);
		x++;
	}
	return (1);
}

int	check_board_col(int **board)
{
	int	x;
	int	y;
	int	check[4];

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
			check[x++] = 0;
		x = 0;
		while (x < 4)
		{
			if (board[x][y] > 0)
				check[board[x][y] - 1]++;
			x++;
		}
		x = 0;
		while (x < 4)
			if (check[x++] > 1)
				return (0);
		y++;
	}
	return (1);
}

int	solve(int **board, int *input, int solved) //입력값이 출력 가능한 경우인지 체크
{
	int	i;
	int	quit;

	i = 1;
	quit = 0;
	if (solved == 16)
	{
		quit = check_answer(board, input);
		return (quit);
	}
	while (i <= 4) //1부터 4까지 넣어줄 것
	{
		board[solved / 4][solved % 4] = i;
		if (check_board_row(board) && check_board_col(board))
		{
			quit = solve(board, input, solved + 1);
			if (quit == 1)
				break ;
		}
		board[solved / 4][solved % 4] = 0;
		i++;
	}
	return (quit);
}
