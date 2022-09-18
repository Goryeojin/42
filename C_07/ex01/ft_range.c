/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:02:23 by rgo               #+#    #+#             */
/*   Updated: 2022/09/10 17:47:19 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	size;
	int			*arr;
	int			i;

	i = 0;
	size = (long long)max - (long long)min;
	if (size <= 0)
		return (0);
	arr = (int *)malloc(sizeof(int) * size);
	while ((long long)i < size)
		arr[i++] = min++;
	return (arr);
}
