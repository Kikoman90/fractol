# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsidler <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/09 13:47:47 by fsidler           #+#    #+#              #
#    Updated: 2016/03/14 12:59:38 by fsidler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
LIB_NAME = ft
LIBDIR = libft
FLAGS = -Wall -Wextra -Werror -O3

HEADERS = includes

SOURCES = srcs/fractal.c \
		  srcs/main.c \

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(LIBDIR)/lib$(LIB_NAME).a $(OBJECTS)
	@$(CC) $(FLAGS) -L $(LIBDIR) -l $(LIB_NAME) -o $@ $^ -lmlx -framework OpenGL -framework AppKit
	@echo "compiling [ $(NAME) ] SUCCESS"

$(LIBDIR)/lib$(LIB_NAME).a : 
	@$(MAKE) -C $(LIBDIR)

all: $(NAME)

%.o: %.c $(HEADERS)/$(NAME).h
	@$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@make clean -C $(LIBDIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBDIR)

re: fclean $(NAME)

.PHONY: all, clean, fclean, re
