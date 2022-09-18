/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:46:43 by rgo               #+#    #+#             */
/*   Updated: 2022/09/01 13:45:27 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*temp;
	unsigned int	i;

	i = 0;
	temp = dest;
	while (*dest)
		dest++;
	while (*src && i < nb)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (temp);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30] = "abcd";
	char *s2 = "efghijklmn";
	unsigned int n = 0;
	printf("strcmp : %s \n %s", ft_strncat(s1, s2, n), strncat(s1, s2, n));
}
*/
