/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:11:44 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/09 15:14:33 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_uitoa(unsigned n)
{
	unsigned long		div;
	int					len;
	char				*arr;

	div = 1;
	len = 0;
	while ((n / div > 0) && ++len > 0)
		div *= 10;
	arr = malloc((++len) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	arr[--len] = '\0';
	while (--len >= 0)
	{
		arr[len] = (n % 10) + 48;
		n = n / 10;
	}
	return (arr);
}
