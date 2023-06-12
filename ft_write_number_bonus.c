/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:54:45 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/09 13:54:25 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_find_previous_space(const char *str, int i)
{
	while (str[i + 1] != '%')
		i--;
	if (str[i] == ' ')
		return (1);
	return (0);
}

int ft_number_flg_mngr(int *positive, int n, char const *str, int i)
{
	int space_control;
	int j;

	space_control = 0;
	j = i;
	while (str[j] != '%')
		j--;
	while(j < i)
	{
		if (space_control == 0 && str[j] == ' ')
			space_control = 1;
		if (str[j] == '+')
		{
			*positive = 1;
			space_control = 2;
		}
		j++;
	}
	if (n >= 0 && (space_control == 1 || \
    (space_control == 0 && !ft_find_previous_space(str, i))))
	{
		write(1, " ", 1);
		return (1);
	}
    return (0);
}

int	ft_number_padding(const char *str, int i, int size)
{
	int j;

	j = i;
	while(str[i] != '%')
		i--;
	if (str[i + 1] != '0')
		return (ft_add_padding(str, i, size, j));
	else
		return (0);
}


int	ft_write_number(va_list lst, char const *str, int i)
{
	int		number;
	char	*content;
	int 	positive;
	int 	space;
	int 	size;

	positive = 0;
	number = va_arg(lst, int);
	space = ft_number_flg_mngr(&positive, number, str, i);
	if (positive == 1 && number >= 0)
		write(1, "+", 1);
	else
		positive = 0;
    if (number < 0)
        space = 0;
	content = ft_itoa(number);
	size = (int)ft_strlen(content);
	free(content);
	space += ft_number_padding(str, i, size);
	ft_putnbr_fd(number, 1);
	space += ft_add_reverse_padding(str, i, size);
	return (size + positive + space);
}
