# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:49:42 by ilbendib          #+#    #+#              #
#    Updated: 2024/01/15 15:21:57 by ilyanbendib      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = serveur

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
_HEADERS = minitalk.h

_SRC_CLIENT = src/client.c
_SRC_SERVER = src/serveur.c

SRC_DIR = .

SRC_CLIENT = $(_SRC_CLIENT:%=$(SRC_DIR)/%)
SRC_SERVER = $(_SRC_SERVER:%=$(SRC_DIR)/%)

HEADERS_DIR = .

HEADERS = $(_HEADERS:%=$(HEADERS_DIR)/%)

OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER = $(SRC_SERVER:.c=.o)

LIBFT_DIR = ./LIBFT
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME_CLIENT) $(NAME_SERVER)

client: $(NAME_CLIENT)

server: $(NAME_SERVER)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(LIBFT_MAKE)
	$(CC) $(OBJS_CLIENT) $(LDFLAGS) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(LIBFT_MAKE)
	$(CC) $(OBJS_SERVER) $(LDFLAGS) $(LIBFT) -o $(NAME_SERVER)

$(LIBFT):
	$(LIBFT_MAKE)

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all client server clean fclean re
