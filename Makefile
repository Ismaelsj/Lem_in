# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 13:39:55 by isidibe-          #+#    #+#              #
#    Updated: 2018/02/12 11:07:18 by isidibe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

SRC = $(SRCDIR)/ft_check.c $(SRCDIR)/ft_error.c $(SRCDIR)/ft_init.c\
$(SRCDIR)/ft_map.c $(SRCDIR)/ft_error_messages.c $(SRCDIR)/ft_invalide_tube.c\
$(SRCDIR)/ft_newsale.c $(SRCDIR)/ft_solve2.c $(SRCDIR)/ft_get_path.c\
$(SRCDIR)/ft_strjoin_free.c $(SRCDIR)/ft_del_last_path.c\
$(SRCDIR)/ft_basic_path.c $(SRCDIR)/ft_write.c $(SRCDIR)/ft_atol.c

INCLUDES = includes

OBJDIR = objects

SRCDIR = srcs

OBJ = $(SRC:$(SRCDIR)/%.c=%.o)

NAME = lem-in

LIB = libft/libft.a

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ./Libft/libft.a

clean:
	@rm -f $(OBJ)
	@rm -rf lem-in.dSYM
	@make clean -C ./libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft

re: fclean all

%.o: $(SRCDIR)/%.c
	@$(CC) -c -o $@ $< $(CFLAGS) -I $(INCLUDES)
