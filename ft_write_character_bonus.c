/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:46:24 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/09 12:35:52 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_chr_flg_manager(const char *str, int i)
{
	int j;

	j = i;
	while(str[i] != '%')
		i--;
	return (ft_add_padding(str, i, 1, j));
}

int	ft_write_character(va_list lst, char const *str, int i)
{
	char	last;
	int 	count;

	last = va_arg(lst, int);
	count = ft_chr_flg_manager(str, i);
	count += (int)write(1, &last, 1);
	count += ft_add_reverse_padding(str, i, 1);
	return (count);
}
