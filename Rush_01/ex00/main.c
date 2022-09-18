/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:02:04 by eunwolee          #+#    #+#             */
/*   Updated: 2022/09/05 11:29:17 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		**init_board(void);
void	init_input(char *str, int *arr);
int		is_valid_input(char *str);
int		solve(int **board, int *input, int solved);
void	print_error(void);
void	print_no_answer(void);
void	print_board(int **board);
void	free_board(int **board);

int	main(int ac, char **av)
{
	int	**board;	//체스판을 채울 이중 포인터
	int	input[16];	//av 입력값을 넣어줄 배열
	int	check_solve;//입력값으로 풀 수 있는 문제인지 체크하는 플래그

	if (ac != 2 || !is_valid_input(av[1])) //매개인자가 두개가 아니거나 입력값이 잘못되었을 경우
	{
		print_error();		//error 출력
		return (0);
	}
	board = init_board();	//이중포인터 공간 할당하여 받아줌
	if (!board)				//할당이 잘못되었을 경우
	{
		print_error();		//error 출력
		return (0);
	}
	init_input(av[1], input);//av 입력값을 input 배열에 담아줌
	check_solve = solve(board, input, 0);//입력값이 출력 가능한 경우인지 체크
	if (check_solve)
		print_board(board);
	else
		print_no_answer();
	free_board(board); //malloc으로 할당해준 포인터 공간 해제
	return (0);
}
