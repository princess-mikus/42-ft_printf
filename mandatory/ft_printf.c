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

static int	ft_starter(char c, va_list lst)
{
	if (c == 'c')
		return (ft_write_character(lst));
	else if (c == 's')
		return (ft_write_string(lst));
	else if (c == 'p')
		return (ft_write_address(lst));
	else if (c == 'd' || c == 'i')
		return (ft_write_number(lst));
	else if (c == 'u')
		return (ft_write_unsigned(lst));
	else if (c == 'x' || c == 'X')
		return (ft_write_hex(lst, c));
	else if (c == '%')
		return ((int)write(1, "%", 1));
	return (-1);
}

int	ft_printf(char const *str, ...)
{
	va_list	lst;
	int		i;
	int		errors;
	int		count;

	i = 0;
	count = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			errors = ft_starter(str[i + 1], lst);
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
