/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:03:28 by rgo               #+#    #+#             */
/*   Updated: 2022/09/10 17:30:13 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_cnt_word(char *str, char *sep)
{
	int	i;
	int	cnt;
	int	flag;

	i = 0;
	cnt = 0;
	flag = 0;
	while (str[i] != 0)
	{
		if (!ft_is_sep(str[i], sep) && flag == 0)
		{
			cnt++;
			flag = 1;
		}
		else if (ft_is_sep(str[i], sep))
			flag = 0;
		i++;
	}
	return (cnt);
}

char	*ft_strdup2(char *src, char *sep)
{
	int		src_len;
	int		i;
	char	*str;

	i = 0;
	src_len = 0;
	while (*(src + src_len) && !ft_is_sep(*(src + src_len), sep))
		src_len++;
	str = (char *)malloc(sizeof(char) * src_len + 1);
	while (i < src_len)
	{
		*(str + i) = *(src + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	char	**s_arr;
	int		wd_cnt;
	int		arr_i;
	int		i;

	i = 0;
	arr_i = 0;
	wd_cnt = ft_cnt_word(str, charset);
	s_arr = (char **)malloc(sizeof(char *) * (wd_cnt + 1));
	while (*(str + i))
	{
		while (*(str + i) && ft_is_sep(*(str + i), charset))
			i++;
		if (*(str + i) && !ft_is_sep(*(str + i), charset))
		{
			s_arr[arr_i] = ft_strdup2((str + i), charset);
			arr_i++;
		}
		while (*(str + i) && !ft_is_sep(*(str + i), charset))
			i++;
	}
	s_arr[arr_i] = 0;
	return (s_arr);
}
