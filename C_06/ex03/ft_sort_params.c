/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:11:58 by rgo               #+#    #+#             */
/*   Updated: 2022/09/08 14:44:58 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 != 0 && *s2 != 0)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	swap(char **i, char **j)
{
	char	*temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void	ft_sort_str_tab(char **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - i)
		{
			if (ft_strcmp(tab[j - 1], tab[j]) > 0)
				swap(&tab[j - 1], &tab[j]);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 1)
		return (0);
	ft_sort_str_tab(++argv, argc - 1);
	while (argv[i])
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
