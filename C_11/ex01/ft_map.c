/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:50:49 by rgo               #+#    #+#             */
/*   Updated: 2022/09/13 14:04:30 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*nbr;
	int	i;

	nbr = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		nbr[i] = f(tab[i]);
		i++;
	}
	return (nbr);
}
