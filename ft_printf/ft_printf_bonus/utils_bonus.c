/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:43:08 by nammari           #+#    #+#             */
/*   Updated: 2021/07/08 00:48:12 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//      4 / 5 functions

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
}

int	error_malloc(void)
{
	ft_putstr("Jesus dude, your malloc failed...\n");
	return (ERROR);
}

int	ft_count_len(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		++i;
	return (i);
}

int	get_biggest(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
