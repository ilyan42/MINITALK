# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanbendib <ilyanbendib@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:49:42 by ilbendib          #+#    #+#              #
#    Updated: 2024/01/14 16:22:40 by ilyanbendib      ###   ########.fr        #
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

all: $(NAME_CLIENT) $(NAME_SERVER)

client: $(NAME_CLIENT)

server: $(NAME_SERVER)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(MAKE) all -C ./LIBFT
	$(CC) $(OBJS_CLIENT) $(LDFLAGS) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(MAKE) all -C ./LIBFT
	$(CC) $(OBJS_SERVER) $(LDFLAGS) -o $(NAME_SERVER)

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) fclean -C ./LIBFT

re: fclean all

.PHONY: all client server clean fclean re
