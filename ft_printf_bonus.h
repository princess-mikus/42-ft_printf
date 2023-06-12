/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:16:55 by fcasaubo          #+#    #+#             */
/*   Updated: 2023/06/09 15:15:58 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);

// Utils
int		ft_putnbru_fd(unsigned int n, int fd);
int		ft_putnbr_hex_fd(unsigned int n, int fd, int mayus);
int		ft_putaddress_fd(unsigned long n, int fd);
char	*ft_uitoa(unsigned n);

// Case by case
int		ft_write_character(va_list lst, char const *str, int i);
int		ft_write_string(va_list lst, char const *str, int i);
int		ft_write_address(va_list lst, char const *str, int i);
int		ft_write_number(va_list lst, char const *str, int i);
int		ft_write_unsigned(va_list lst, const char *str, int i);
int	    ft_write_hex(va_list lst, char c, char const *str, int i);

// Padding
int		ft_add_padding(char const *str, int i, int size, int max_length);
int		ft_add_reverse_padding(char const *str, int i, int size);

#endif //FT_PRINTF_H
