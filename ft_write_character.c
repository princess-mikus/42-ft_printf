/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:46:24 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/06 15:04:37 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_character(va_list lst)
{
	int		errors;
	char	*last;

	last = malloc(1 * sizeof(char));
	last[0] = va_arg(lst, int);
	errors = write(1, &(last[0]), 1);
	free(last);
	return (1);
}
