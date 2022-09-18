/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:16:34 by eunwolee          #+#    #+#             */
/*   Updated: 2022/09/05 11:29:16 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**init_board(void)
{
	int	**board;
	int	i;
	int	j;

	board = (int **)malloc(sizeof(int *) * 4); //포인터 배열 4개짜리를 갖고있는 이중포인터 공간 할당
	i = 0;
	while (i < 4) //이중포인터 배열 하나씩 int 배열 4개 할당
	{
		board[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	if (!board) //할당이 잘못되었다면 0 리턴
		return (0);
	i = 0;
	while (i < 4) //할당이 잘 되었을 경우 board 16칸 0으로 채워주기
	{
		j = 0;
		while (j < 4)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}

void	init_input(char *str, int *arr) //av 입력값을 input 배열에 담아줌
{
	int	idx;

	idx = 0;
	while (*str) //av 배열 끝까지
	{
		if (*str >= '1' && *str <= '4') //해당 값이 1~4라면
		{
			arr[idx++] = *str - '0';	//input 배열의 처음부터 char형으로 저장
		}
		str++;
	}
	return ;
}

int	is_valid_input(char *str)
{
	int	i;
	int	num;
	int	was_space;

	i = 0;
	num = 0;
	was_space = 1; //이전 문자가 공백이었는지
	while (str[i]) //av끝까지 검사
	{
		if (str[i] == 32 && was_space == 0)  //공백이거나 스페이스가 아니었으면
			was_space++;	// +1
		else if ((str[i] >= '1' && str[i] <= '4') && was_space == 1) //현재 인덱스가 1~4까지고 스페이스가 나왔었다면
		{
			num++; //숫자 갯수 +1
			was_space--; //이전에 공백이 아니었다고 바꿈
		}
		i++;
	}
	if (num != 16 || i != 31) //문자가 16개, 공백합쳐서 총 문자 수가 31개가 아니라면 잘못된 입력값
		return (0);	//0 반환
	return (1);
}

void	free_board(int **board) //이중포인터 board 공간 할당 해제
{
	int	i;

	i = 0;
	while (i < 4) //int배열 4개부터 해제
	{
		free(board[i]);
		i++;
	}
	free(board); //이중포인터 board해제
	return ;
}
