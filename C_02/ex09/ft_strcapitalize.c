/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:19:56 by rgo               #+#    #+#             */
/*   Updated: 2022/09/05 16:38:46 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_lowercase(str);
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if ((i == 0) || \
				(!('a' <= str[i - 1] && str[i - 1] <= 'z') && \
				!('A' <= str[i - 1] && str[i - 1] <= 'Z') && \
				!('0' <= str[i - 1] && str[i - 1] <= '9')))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
