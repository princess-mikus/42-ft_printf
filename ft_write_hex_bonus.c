/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:02:33 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/12 11:20:23 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_hex_flg_mngr(int *format, char const *str, int i, int size)
{
    int j;

    j = i;
    while (str[j] != '%')
        j--;
    while(j < i)
    {
        while (str[j] == ' ')
            j++;
        if (str[j] == '#')
            *format = 2;
        j++;
    }
	return (ft_add_padding(str, j, size, i));
}

int	ft_write_hex(va_list lst, char c, char const *str, int i)
{
	int		number;
    int		format;
	int		count;
	char	*temp;
	int 	size;

    format = 0;
	number = va_arg(lst, int);
	temp = ft_itoa(number);
	size = (int)ft_strlen(temp) + 2;
	count = ft_hex_flg_mngr(&format, str, i, size);
	free(temp);
	if (format == 2 && number != 0)
	{
		if (c == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
	}
	if (number == 0)
		format = 0;
	if (c == 'x')
		count += ft_putnbr_hex_fd(number, 1, 0) + format;
	else
		count += ft_putnbr_hex_fd(number, 1, 1) + format;
	return (count + ft_add_reverse_padding(str, i, size));
}
