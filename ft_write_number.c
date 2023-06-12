/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:54:45 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/06 12:19:14 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_number(va_list lst)
{
	int		number;
	char	*content;

	number = va_arg(lst, int);
	ft_putnbr_fd(number, 1);
	content = ft_itoa(number);
	number = (int)ft_strlen(content);
	free(content);
	return (number);
}
