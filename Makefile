# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:49:42 by ilbendib          #+#    #+#              #
#    Updated: 2024/01/22 16:04:22 by ilyanbendib      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CLIENT = src/client.c
SRCS_SERVER = src/serveur.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft

LIBFT_DIR = ./LIBFT
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(LIBFT_MAKE)
	$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJS_SERVER) -o $(NAME_SERVER) $(LDFLAGS)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(LIBFT_MAKE)
	$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJS_CLIENT) -o $(NAME_CLIENT) $(LDFLAGS)

%.o: %.c include/minitalk.h
	$(CC) $(CFLAGS) -Iinclude -Ilibft -c $< -o $@

$(LIBFT):
	$(LIBFT_MAKE)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: clean fclean re all