/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:41:00 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/13 18:41:02 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr_len(char *s)
{
	size_t	len;
	
	len = 0;
	if (s)
	{
		while (s[len] != '\0')
		{
			write(1, s++, 1);
			len++;
		}
	}
	return(len);
}

void			printc(t_format *f, va_list *ap, int *charcount)
{
	char *s;

	s = ft_strnew(f->width);
	charcount = &ft_putstr_len()
}

