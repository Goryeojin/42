/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:46:21 by rgo               #+#    #+#             */
/*   Updated: 2022/09/10 18:43:47 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (*(s1 + i) || *(s2 + i)))
	{
		if (*(s1 + i) != *(s2 + i))
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
		i++;
	}
	return (0);
}


#include <stdio.h>
#include <string.h>

int main()
{
	// char *s1 = "abcD";
	// char *s2 = "abcd";

	char a[10] = "HELLO WW";
	char b[10] = "";
	unsigned int n = 20;
	printf("strcmp : %d \nft_strcmp : %d", strncmp(a, b, n),
	 ft_strncmp(a, b, n));
}
