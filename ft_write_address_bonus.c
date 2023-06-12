/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:23:17 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/09 12:39:13 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_write_address(va_list lst, char const *str, int i)
{
	void	*ptr;
	int 	count;

	ptr = va_arg(lst, void *);
	write(1, "0x", 2);
	count = ft_putaddress_fd((unsigned long)ptr, 1) + 2;
	count += ft_add_reverse_padding(str, i, count);
	return (count);
}
