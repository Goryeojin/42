/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:52:03 by rgo               #+#    #+#             */
/*   Updated: 2022/09/13 21:05:11 by rgo              ###   ########.fr       */
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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = (ft_strlen(tab));
	while (i < size - 1)
	{
		j = 1;
		while (j < size - i)
		{
			if (cmp(tab[j - 1], tab[j]) > 0)
				swap(&tab[j - 1], &tab[j]);
			j++;
		}
		i++;
	}
}
