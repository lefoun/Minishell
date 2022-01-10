/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:42:09 by nammari           #+#    #+#             */
/*   Updated: 2021/07/07 14:48:24 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//      1 / 5 functions

bool	is_specifier(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 's'
		|| c == 'p' || c == 'u' || c == 'x'
		|| c == 'X')
		return (true);
	return (false);
}

bool	ft_ishex(char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (true);
	return (false);
}
