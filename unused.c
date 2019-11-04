char		*detect_type(const char *restrict format, int charcount)
{
	char * type;

	type = "undefined";
	while (format[charcount] != '%')
	{
		if (format[charcount] == 's')
			type = "char *";
		else if (format[charcount] == 'p')
			type = "void *";
		else if (format[charcount] == 'd')
			type = "int";
		else if (format[charcount] == 'i')
			type = "int";
		else if (format[charcount] == 'o')
			type = "unsigned int";
		else if (format[charcount] == 'u')
			type = "unsigned int";
		else if (format[charcount] == 'x')
			type = "unsigned int";
		else if (format[charcount] == 'X')
			type = "unsigned int";
		else if (format[charcount] == 'c')
			type = "char";
		charcount++;
	}
	return (type);
}

size_t		validate_format_specifier(const char *restrict format, size_t i)
{
	size_t valid;

	valid = 0;
	while(format[i] != '\0')
	{
		i++;
		if (TYPE(format[i]))
		{
			valid += i;
			break;
		}
	}
	return(valid);
}

int			validate_format(t_format *f)
{
	if (TYPE(f->specifier))
		return(1);
	return (0);
}

void	str_precision_handler(char **str, t_format *f, int *len)
{
	//char	*new;
	
	if (f->precision > 0 && f->precision < *len)
	{
		*str[*len] = '\0';
		//ft_strncat();
		*len = f->precision;
	}
}

void		get_oxx_str(t_format *f, va_list *ap, char **str)
{
	if (f->length || !f->length)
	{
	//if (f->length == 0)
		if (f->length == 1)
			*str = ft_strdup(ft_hitoa((short int)va_arg(*ap, int)));
		else if (f->length == 2)
			*str = ft_strdup(ft_hhitoa((signed char)va_arg(*ap, int)));
		else if (f->length == 3)
			*str = ft_strdup(ft_litoa(va_arg(*ap, unsigned long int)));
		else if (f->length == 4)
			*str = ft_strdup(ft_llitoa(va_arg(*ap, long long int)));
		/*else if (f->length == 5)
			*str = ft_strdup(ft_Litoa(va_arg(*ap, long long int)));
		else if (f->length == 7)
			*str = ft_strdup(ft_jitoa(va_arg(*ap, long long int)));
		else if (f->length == 9)
			*str = ft_strdup(ft_zitoa(va_arg(*ap, long long int)));*/
		else if (f->specifier == 'o')
			*str = ft_strdup(ft_itoa_base(va_arg(*ap, int), 8));
        else if (f->specifier == 'x' || f->specifier == 'X')
		{
			*str = ft_strdup(ft_itoa_base(va_arg(*ap, int), 16));
			if (f->specifier == 'x')
				str_tolower(str);
		}		
        else
			*str = ft_strdup(ft_itoa(va_arg(*ap, int)));
	}
	if (!(*str))
	{
		*str = malloc(sizeof(char) * 7);
		*str = "(null)";
	}
}