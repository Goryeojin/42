/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:38:23 by rgo               #+#    #+#             */
/*   Updated: 2022/09/08 09:56:31 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int i, int j, int *tab)
{
	int	temp;

	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - i)
		{
			if (tab[j - 1] > tab[j])
				swap(j - 1, j, tab);
			j++;
		}
		i++;
	}
}


int main(){
	int arr[5] = {1, 7, 5, 2, 6};
	ft_sort_int_tab(arr, 5);
}
