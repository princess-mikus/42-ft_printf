/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:02:33 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/15 12:50:49 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex(va_list lst, char c, t_data data)
{
	int	number;
	int ret;
	char *buffer[1];

	ret = 0;
	buffer[0] = data.character;
	if (data.hex_flag == true)
	{
		ret = write(1, "0", 1);
		ret += write(1, buffer, 1);
		if (ret != 2)
			return (-1);
	}
	number = va_arg(lst, int);
	if (c == 'x')
		return (ft_putnbr_hex_fd(number, 1, 0) + ret);
	else
		return (ft_putnbr_hex_fd(number, 1, 1) + ret);
}
