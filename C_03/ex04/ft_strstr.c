/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:46:52 by rgo               #+#    #+#             */
/*   Updated: 2022/09/10 18:46:07 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	idx;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		idx = 0;
		while (*(str + idx) == *(to_find + idx))
		{
			idx++;
			if (*(to_find + idx) == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char *s1 = "sssisa";
	char *s2 = "is";
	// char s3[2] = {200, 'a'};

	char a[10] = {'H', 'E', 'L', 'L', 'O'};
	char b[10] = {'H', 'E', 'L', 200, '0'};
	printf("strcmp : %s \nft_strcmp : %s", strstr(s1, s2), ft_strstr(s1, s2));
}

