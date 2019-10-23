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