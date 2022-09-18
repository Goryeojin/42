/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:45:44 by rgo               #+#    #+#             */
/*   Updated: 2022/09/10 18:42:34 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 != 0 && *s2 != 0)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char *s1 = "a";
	char *s2 = "ab";

	char a[10] = {'H', 'E', 'L', 'L', 'O'};
	char b[10] = {'H', 'E', 'L', 200, '0'};
	printf("strcmp : %d \nft_strcmp : %d", strcmp(a, b), ft_strcmp(a, b));
}
*/
