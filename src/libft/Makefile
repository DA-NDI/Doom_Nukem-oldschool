#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolgin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 18:42:23 by avolgin           #+#    #+#              #
#    Updated: 2018/07/15 19:35:45 by avolgin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC_LIB =./libft/ft_atoi.c \
		./libft/ft_bzero.c \
		./libft/count_bits.c \
		./libft/ft_count_digits.c \
		./libft/ft_intlen.c \
		./libft/ft_is_whitespace.c \
		./libft/ft_isalnum.c \
		./libft/ft_isalpha.c \
		./libft/ft_isascii.c \
		./libft/ft_isdigit.c \
		./libft/ft_isprint.c \
		./libft/ft_itoa.c \
		./libft/ft_itoa_unsigned.c \
		./libft/ft_itoa_base.c \
		./libft/ft_itoa_base_10_8.c \
		./libft/ft_itoa_base_10_16.c \
		./libft/ft_itoa_base_10_16x.c \
		./libft/ft_itoa_long.c \
		./libft/ft_itoa_long_long.c \
		./libft/ft_itoa_long_long_u.c \
		./libft/ft_fill_zero.c \
		./libft/ft_lstadd.c \
		./libft/ft_lstdel.c \
		./libft/ft_lstdelone.c \
		./libft/ft_lstiter.c \
		./libft/ft_lstmap.c \
		./libft/ft_lstnew.c \
		./libft/ft_memalloc.c \
		./libft/ft_memccpy.c \
		./libft/ft_memchr.c \
		./libft/ft_memcmp.c \
		./libft/ft_memcpy.c \
		./libft/ft_memdel.c \
		./libft/ft_memmove.c \
		./libft/ft_memset.c \
		./libft/ft_pow.c \
		./libft/ft_putchar.c \
		./libft/ft_putchar_fd.c \
		./libft/ft_putendl.c \
		./libft/ft_putendl_fd.c \
		./libft/ft_putnbr.c \
		./libft/ft_putnbr_fd.c \
		./libft/ft_putstr.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_reverse.c \
		./libft/ft_reverse_bitwise.c \
		./libft/ft_rot_n.c \
		./libft/ft_strcat.c \
		./libft/ft_strchr.c \
		./libft/ft_strclr.c \
		./libft/ft_strcmp.c \
		./libft/ft_strcpy.c \
		./libft/ft_strdel.c \
		./libft/ft_strdup.c \
		./libft/ft_strequ.c \
		./libft/ft_striter.c \
		./libft/ft_striteri.c \
		./libft/ft_strjoin.c \
		./libft/ft_strjoin_del.c \
		./libft/ft_strjoin_del_dest.c \
		./libft/ft_strjoin_del_all.c \
		./libft/ft_strlcat.c \
		./libft/ft_strlen.c \
		./libft/ft_strlen_w.c \
		./libft/ft_strmap.c \
		./libft/ft_strmapi.c \
		./libft/ft_strncat.c \
		./libft/ft_strncmp.c \
		./libft/ft_strncpy.c \
		./libft/ft_strnequ.c \
		./libft/ft_strnew.c \
		./libft/ft_strnstr.c \
		./libft/ft_strrchr.c \
		./libft/ft_strsplit.c \
		./libft/ft_strstr.c \
		./libft/ft_strsub.c \
		./libft/ft_strtol.c \
		./libft/ft_strtrim.c \
		./libft/ft_strzero.c \
		./libft/ft_swap_bits.c \
		./libft/ft_tolower.c \
		./libft/ft_toupper.c \
		./libft/get_next_line.c

SRC_PRINTF = ./ft_printf/ft_printf.c \
		./ft_printf/ft_parse_all.c \
		./ft_printf/ft_print_d_i.c \
		./ft_printf/ft_handle_o.c \
		./ft_printf/ft_handle_u.c \
		./ft_printf/ft_handle_big_u.c \
		./ft_printf/ft_handle_big_o.c \
		./ft_printf/ft_handle_big_d.c \
		./ft_printf/ft_handle_x.c \
		./ft_printf/ft_handle_c.c \
		./ft_printf/ft_handle_s.c \
		./ft_printf/ft_handle_p.c \
		./ft_printf/ft_handle_percent.c \
		./ft_printf/unicode.c

OBJECT_LIB = $(SRC_LIB:.c=.o)

INCLUDES = -I ./includes

OBJECT_PRINTF = $(SRC_PRINTF:.c=.o)

FLAGS = -Wall -Wextra

all: $(NAME)

$(NAME) : $(OBJECT_LIB) $(OBJECT_PRINTF)
		@echo "\033[0;32mLib compiled\033[0;0m"
		@ar rc $(NAME) $(OBJECT_LIB) $(OBJECT_PRINTF)
		@ranlib $(NAME)
%.o: %.c
		@gcc -g $(FLAGS) -o $@ -c $< $(INCLUDES)
clean:
		@/bin/rm -f $(OBJECT_LIB)
		@/bin/rm -f $(OBJECT_PRINTF)
fclean: clean
		@/bin/rm -f ./libft/libft.a
		@/bin/rm -f $(NAME)
re:		fclean all

tags:
		rm -f TAGS
		etags -e -R *.c *.h
