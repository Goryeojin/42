/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgo <rgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:18:38 by rgo               #+#    #+#             */
/*   Updated: 2022/09/13 20:18:47 by rgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void	ft_do_op(int num1, int op, int num2);
int		add(int num1, int num2);
int		sub(int num1, int num2);
int		div(int num1, int num2);
int		mul(int num1, int num2);
int		mod(int num1, int num2);
void	ft_putnbr(int nb);

#endif
