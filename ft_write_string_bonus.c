/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:49:05 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/09 14:23:26 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_str_flg_manager(const char *str, int i, int size, int *max_width)
{
	int		 j;
	int		 k;
	char	 *temp;

	j = i;
    while(str[i] != '%')
	{
		if (str[i] == '.')
		{
			k = i + 1;
			while (str[k] >= '0' && str[k] <= '9')
				k++;
			temp = ft_substr(str, i + 1, k - i - 1);
			*max_width = ft_atoi(temp);
			free(temp);
		}
		i--;
	}
	if (*max_width == -1)
		return (ft_add_padding(str, i, size, j));
	else
		return (0);
}

int	ft_write_string(va_list lst, char const *str, int i)
{
	char	*last;
	int 	count;
	int 	max_width;
	int 	size;

	max_width = -1;
	last = va_arg(lst, char *);
    size = (int)ft_strlen(last);
	count = ft_str_flg_manager(str, i, size, &max_width);
	if (last == NULL)
	{
		if (max_width == -1)
			max_width = 6;
		count = (int) write(1, "(null)", max_width);
		count += ft_add_reverse_padding(str, i, size);
		return (count);
	}
	if (max_width > -1 && max_width < size)
		size = max_width;
	write(1, last, size);
	count += ft_add_reverse_padding(str, i, (int)ft_strlen(last));
	return (size + count);
}
