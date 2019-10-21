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

t_format	*parse_format(const char *format, va_list *ap, size_t *i)
{
	t_format *f;
    
    f = malloc(sizeof(t_format));
    (*i)++;    //maybe not
    reset_format(f);
	parse_flags(f, format, i);
    parse_width(f, format, i, ap);
    parse_precision(f, format, i, ap);
    parse_length(f, format, i);
    parse_type(f, format, i);
	return(f);
}



