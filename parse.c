/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:36:53 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/13 16:37:01 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
size_t		parse_printf_format(const char *template, size_t n, int *argtypes)
{
*/

size_t	parse_format(t_format *f, const char *restrict format, size_t i)
{
	reset_format(f);
	i = parse_flags(f, format, i);
    i = parse_width(f, format, i);
    i = parse_precision(f, format, i);
    i = parse_length(f, format, i);
	return(i);
}



