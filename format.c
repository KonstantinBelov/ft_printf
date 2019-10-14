/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:34:34 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/12 15:38:08 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_format(t_format *f)
{
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
	f->null = 0;
	f->number = 0;
	f->width = 0;
	f->precision = -1;
	f->length = "a";
	f->specifier = 'a';
}

int			validate_format(t_format *f)
{
	if (TYPE(f->specifier))
		return(1);
	return (0);
}