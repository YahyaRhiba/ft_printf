# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 21:15:12 by yrhiba            #+#    #+#              #
#    Updated: 2022/10/25 21:15:45 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf

SUFC = .c
SUFO = .o
OBJS_DIR = objs/
LIBFT_OBJS_DIR = libft/objs/
LIBFT_NAME = libft/libft.a

SRCS = $(addsuffix $(SUFC), $(FILES))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix $(SUFO), $(FILES)))

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS) libft_all
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

libft_all :
	make bonus -C libft

all : $(NAME)

$(OBJS_DIR)%.o : %.c libftprintf.h
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C libft
	rm -rf $(OBJS_DIR)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

.PHONEY : all flcean clean re
