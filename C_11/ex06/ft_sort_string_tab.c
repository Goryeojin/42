/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:51:49 by rgo               #+#    #+#             */
/*   Updated: 2022/09/13 21:05:16 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	swap(char **i, char **j)
{
	char	*temp;

	temp = *i;
	*i = *j;
	*j = temp;
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

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_strlen(tab);
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
