/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:23:26 by rgo               #+#    #+#             */
/*   Updated: 2022/09/07 11:12:36 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	sum;

	sum = 1;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power < 1)
		return (0);
	while (power >= 1)
	{
		sum *= nb;
		power--;
	}
	return (sum);
}
