/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:49:05 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/07 15:52:12 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_string(va_list lst)
{
	char		*last;

	last = va_arg(lst, char *);
	ft_putstr_fd(last, 1);
	if (last == NULL)
		return (write(1, "(null)", 6));
	return ((int)ft_strlen(last));
}
