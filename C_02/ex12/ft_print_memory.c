/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:39:55 by rgo               #+#    #+#             */
/*   Updated: 2022/09/10 13:44:17 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, unsigned int idx)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < idx)
		{
			if (32 <= str[i] && str[i] <= 126)
				write(1, &str[i], 1);
			else
				write(1, ".", 1);
		}
		i++;
	}
}

void	ft_putstr_hex(char *str, unsigned int idx)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < idx)
		{
			write(1, &"0123456789abcdef"[(unsigned char)str[i] / 16], 1);
			write(1, &"0123456789abcdef"[(unsigned char)str[i] % 16], 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_putnbr(unsigned long long addr)
{
	if (addr < 16)
	{
		write(1, &"0123456789abcdef"[addr % 16], 1);
		return ;
	}
	else if (addr >= 16)
	{
		ft_putnbr(addr / 16);
		write(1, &"0123456789abcdef"[addr % 16], 1);
	}
}

void	ft_putzero(unsigned long long addr)
{
	unsigned long long	temp;
	int					i;

	temp = addr;
	i = 1;
	while (i < 16)
	{
		if (temp < 16)
			write(1, "0", 1);
		temp /= 16;
		i++;
	}
	ft_putnbr(addr);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)addr;
	while (*str && i < size)
	{
		if (i % 16 == 0)
		{
			ft_putzero((unsigned long long)str);
			write(1, ": ", 2);
			ft_putstr_hex(str, size - i);
			ft_putstr(str, size - i);
			write(1, "\n", 1);
		}
		i++;
		str++;
	}
	return (addr);
}

int main()
{
	char addr[93] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
	ft_print_memory(addr, 52);
}
