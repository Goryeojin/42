/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:47:03 by rgo               #+#    #+#             */
/*   Updated: 2022/09/10 18:50:49 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (dest_len >= size)
		return (src_len + size);
	while (*dest)
		dest++;
	while (*src && dest_len + i + 1 < size)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30] = "1234";
	char *s2 = "456789";
	unsigned int size = 10;
	printf("strstr : %u\n %lu\n", ft_strlcat(s1, s2, size), strlcat(s1, s2, size));
	printf("%s\n", s1);

}
*/
