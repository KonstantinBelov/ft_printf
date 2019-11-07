# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbelov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 14:25:08 by kbelov            #+#    #+#              #
#    Updated: 2019/10/24 18:47:57 by kbelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

SRC = ft_printf.c format.c parse.c parse_helpers.c output.c output_d.c \
		output_oxx.c output_f.c ft_ullitoa_base_.c

OBJ = *.o

LIBFT = ./libft/*.c

HEADER = ft_printf.h

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC) $(LIBFT)
	ar rcs $(NAME) $(OBJ)

lib:
	@make -C libft

clean:
	@/bin/rm -rf $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

test: lib
	gcc $(FLAG) $(SRC) main.c libft/libft.a -o ft_printf_makefile

lldb: lib
	gcc -g $(FLAG) $(SRC) main.c libft/libft.a -o ft_printf_lldb

lldb_run:
	lldb ft_printf_lldb "Hello World!"

dev:
	gcc $(FLAG) main.c verify.c prepare_dev_mode.c fillit_dev_mode.c libft/libft.a -o fillit_dev_mode #-fsanitize=address

dev_lldb:
	gcc -g $(FLAG) main.c verify.c prepare_dev_mode.c fillit_dev_mode.c libft/libft.a -o fillit_dev_lldb

no_comment:
	gcc $(FLAG) main.c verify.c prepare_dev_mode.c fillit_no_comment.c libft/libft.a -o fillit_no_comment
