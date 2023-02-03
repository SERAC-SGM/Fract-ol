# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:55:37 by lletourn          #+#    #+#              #
#    Updated: 2023/01/29 10:20:28 by lletourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang
CFLAGS		= -Wall -Werror -Wextra

AR			= ar -rcs

SRCS 	= checks.c		\
		  convert.c		\
		  write_char.c	\
		  write_nbr.c	\
		  ft_printf.c


NAME	= libftprintf.a

DEPS	= ft_printf.h

OBJS		= $(SRCS:.c=.o)
OBJS_DIR	= objs/
OBJS_PATH	= $(addprefix $(OBJS_DIR), $(OBJS))

$(OBJS_DIR)%.o: %.c $(DEPS) 
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS_PATH)
	$(AR) $(NAME) $(OBJS_PATH)

all: $(NAME)

clean: 
	rm -rf $(OBJS_DIR)

fclean: clean 
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re 
