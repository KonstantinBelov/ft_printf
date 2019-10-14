/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:36:31 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/13 17:36:37 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int        parse_flags(t_format *f, const char *restrict format, size_t i)
{
    while (FLAGS(format[i]))
    {    
        if (format[i] == '-')
            f->minus = 1;
        else if (format[i] == '+')
            f->plus = 1;
        else if (format[i] == ' ')
            f->plus = 1;
        else if (format[i] == '#')
            f->plus = 1;
        else if (format[i] == '0')
            f->plus = 1;
        i++;
    }
    return(i);
}

int         parse_width(t_format *f, const char *restrict format, size_t i)
{
    f->width = ft_atoi((const char *)(format + i));
    while (format[i] >= '0' && format[i] <= '9')
        i++;
    return(i);
}

int         parse_precision(t_format *f, const char *restrict format, size_t i)
{
    if (format[i] == '.')
    {
        i++;
        f->precision = ft_atoi((const char *)(format + i));
        while (format[i] >= '0' && format[i] <= '9')
            i++;
    }
    return(i);
}

int			parse_length(t_format *f, const char *restrict format, size_t i)
{
    if (format[i] == 'h' || format[i] == 'l')
    {
        f->length[0] = format[i];
        i++;
    }
    if (format[i] == 'h' || format[i] == 'l')
    {
        f->length[1] = format[i];
        i++;
    }
    return(i);
}

int			parse_type(t_format *f, const char *restrict format, size_t i)
{
    if (TYPE(format[i]))
    {
        f->specifier = format[i];
        i++;
    }
    return (i);
}