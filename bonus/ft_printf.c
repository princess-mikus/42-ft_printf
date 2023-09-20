/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:26:19 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/19 11:34:19 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_starter(char const *str, va_list lst, t_data data, int i)
{
	data.character = ft_get_char(str, i);
	ft_get_flags(str, lst, &data, int i);
	if (data.character == 'c')
		return (ft_write_character(lst, data));
	else if (data.character == 's')
		return (ft_write_string(lst, data));
	else if (data.character == 'p')
		return (ft_write_address(lst, data));
	else if (data.character == 'd' || c == 'i')
		return (ft_write_number(lst, data));
	else if (data.character == 'u')
		return (ft_write_unsigned(lst, data));
	else if (data.character == 'x' || data.character == 'X')
		return (ft_write_hex(lst, data));
	else if (data.character == '%')
		return ((int)write(1, "%", 1));
	return (-1);
}

int	ft_printf(char const *str, ...)
{
	va_list	lst;
	int		i;
	int		errors;
	int		count;
	t_data	data;

	i = 0;
	count = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			errors = ft_starter(str, lst, data, i);
			i += 2;
		}
		else
			errors = write(1, &(str[i++]), 1);
		if (errors == -1)
			return (-1);
		count += errors;
	}
	return (count);
}
