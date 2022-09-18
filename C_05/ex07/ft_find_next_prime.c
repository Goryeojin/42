/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:24:27 by rgo               #+#    #+#             */
/*   Updated: 2022/09/07 14:28:09 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(long long nb)
{
	long long	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	long long	i;

	if (nb <= 2)
		return (2);
	i = nb;
	while (i < (long long)nb * 2)
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
	return (0);
}
