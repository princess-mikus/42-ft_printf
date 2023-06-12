/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:00:11 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/09 16:10:47 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_unsigned_flg_mngr(const char *str, int i, int size)
{
	int	j;

	j = i;
	while (str[i] != '%')
		i--;
	return (ft_add_padding(str, i, size, j));
}

int	ft_write_unsigned(va_list lst, const char *str, int i)
{
	unsigned int	number;
	int 			size;
	int 			count;
	char 			*temp;

	number = va_arg(lst, unsigned int);
	temp = ft_uitoa(number);
	size = (int)ft_strlen(temp);
	free(temp);
	count = ft_unsigned_flg_mngr(str, i, size);
	ft_putnbru_fd(number, 1);
	count += ft_add_reverse_padding(str, i, size);
	return (count + size);
}
