/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:26:19 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/12 10:42:19 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"


int ft_skip_flags(char const *str, int i)
{
	while (str[i] == ' ' || str[i] == '+' || str[i] == '#' || \
	(str[i] >= '0' && str[i] <= '9') || str[i] == '-' \
	|| str[i] == '.')
		i++;
	return (i);
}

int ft_search_start_of_argument(char const *str, int  i)
{
    while (str[i] != '%')
        i--;
    return (i);
}

int	ft_starter(char const *str, va_list lst, int i)
{
	char    c;
    int     count;

	c = str[i];
	if (c == 'c')
		return (ft_write_character(lst, str, i));
	else if (c == 's')
		return (ft_write_string(lst, str, i));
	else if (c == 'p')
		return (ft_write_address(lst, str, i));
	else if (c == 'd' || c == 'i')
		return (ft_write_number(lst, str, i));
	else if (c == 'u')
		return (ft_write_unsigned(lst, str, i));
	else if (c == 'x' || c == 'X')
		return (ft_write_hex(lst, c, str, i));
	else if (c == '%')
    {
        count = ft_add_padding(str, ft_search_start_of_argument(str, i - 1) - 1, 1, i);
        count += (int)write(1, "%", 1);
        return (ft_add_reverse_padding(str, i  - 1, 1) + count);
    }
    return (-1);
}

int	ft_printf(char const *str, ...)
{
	va_list	lst;
	int		i;
	int		count;
    int     space;

	i = 0;
	count = 0;
    space = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = ft_skip_flags(str, i + 1);
			count += ft_starter(str, lst, i);
			if (count == -1)
				return (0);
			i++;
		}
		else
		{
            if (str[i] == ' ')
                space += 1;
            else if (str[i] != ' ')
                space = 0;
			write(1, &(str[i]), 1);
			i++;
			count++;
		}
	}
    va_end(lst);
	return (count);
}
