/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:23:17 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/06 12:23:31 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_address(va_list lst)
{
	void	*ptr;

	ptr = va_arg(lst, void *);
	write(1, "0x", 2);
	return (ft_putaddress_fd((unsigned long)ptr, 1) + 2);
}
