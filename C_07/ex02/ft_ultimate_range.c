/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:02:36 by rgo               #+#    #+#             */
/*   Updated: 2022/09/10 18:53:52 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	size;
	int			i;

	i = 0;
	size = (long long)max - (long long)min;
	if (size <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * size);
	if (!(*range))
		return (-1);
	while ((long long)i < size)
		(*range)[i++] = min++;
	return (size);
}
