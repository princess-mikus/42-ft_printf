# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 11:53:01 by fcasaubo          #+#    #+#              #
#    Updated: 2023/06/19 12:02:57 by fcasaubo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=   libftprintf.a
CC				=   gcc
CFLAGS			=   -Wall -Wextra -Werror
AR				=   ar
ARFLAGS			=   rcs
RM				=   rm -rf
SRC				=	ft_printf			\
					ft_putnbr_hex_fd	\
					ft_putnbru_fd 		\
					ft_putaddress_fd	\
					ft_write_character	\
					ft_write_string		\
					ft_write_address	\
					ft_write_number		\
					ft_write_unsigned	\
					ft_write_hex		\
					ft_uitoa			\
					ft_putnbrpf_fd

SRCS			=	$(addsuffix .c, $(SRC))
OBJ_DIR			=	obj
OBJS			=   $(SRCS:%.c=$(OBJ_DIR)/%.o)
BOBJS			=   $(BSRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_PATH		=   ./libft
LIBFT			=   $(LIBFT_PATH)/libft.a
$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
					cp  $(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)
$(LIBFT):
					make -C $(LIBFT_PATH) all
$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all
.PHONY:				all clean fclean re libft