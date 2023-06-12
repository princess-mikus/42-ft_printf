/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_padding_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:31:48 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/12 10:52:39 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_add_padding(char const *str, int i, int size, int max_length)
{
	char *temp;
	int j;
	int count;
	int number;

	count = 0;
	while ((str[i] < '0' || str[i] > '9') && i < max_length && str[i] != '-')
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] >= '0' && str[i] <= '9')
	{
		j = i;
		while (str[j] >= '0' && str[j] <= '9')
			j++;
		temp = ft_substr(str, i, j);
		number = ft_atoi(temp);
		free(temp);
		while (number-- > size)
			count += (int) write(1, " ", 1);
		return (count);
	}
	return (0);
}

int	ft_add_reverse_padding(char const *str, int i, int size)
{
	char	*temp;
	int		j;
	int 	count;
	int		number;
	int		max_length;

	count = 0;
	max_length = i;
	while (str[i] != '%' && str[i] != '-')
		i--;
	if (str[i] == '%')
		return (0);
	while ((str[i] < '0' || str[i] > '9') && i < max_length)
		i++;
	if (str[i] >= '0' && str[i] <= '9')
	{
		j = i;
		while (str[j] >= '0' && str[j] <= '9')
			j++;
		temp = ft_substr(str, i, j);
		number = ft_atoi(temp);
		free(temp);
		while (number-- > size)
			count += (int) write(1, " ", 1);
		return (count);
	}
	return (0);
}