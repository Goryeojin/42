/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:46:33 by rgo               #+#    #+#             */
/*   Updated: 2022/09/01 11:27:02 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(dest + i))
		i++;
	while (*src)
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30] = "abcd";
	char *s2 = "efg";
	printf("strcmp : %s", ft_strcat(s1, s2));
}
*/
