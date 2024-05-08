# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 21:09:25 by abmahfou          #+#    #+#              #
#    Updated: 2024/05/08 16:26:27 by abmahfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

SERVER = server

CFLAGS = -Wall -Wextra -Werror

CC = cc

RM = rm -rf

HEADER = minitalk.h

PRINTF = printf/libftprintf.a

SRC_C = client.c \
		utils.c

SRC_S = server.c \
		utils.c

OBJS_C = $(SRC_C:.c=.o)

OBJS_S = $(SRC_S:.c=.o)

all: $(NAME) $(SERVER)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

$(SERVER): $(OBJS_S)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJS_S) -o $(SERVER)

$(NAME): $(OBJS_C)
	make -C printf
	$(CC) $(CFLAGS) $(PRINTF) $(OBJS_C) -o $(NAME)
	@echo " __    __     __     __   __     __     ______   ______     __         __  __    "
	@echo "/\\ \"-./  \\   /\\ \\   /\\ \"-.\\ \\   /\\ \\   /\\__  _\\ /\\  __ \\   /\\ \\       /\\ \\/ /    "
	@echo "\\ \\ \\-./\\ \\  \\ \\ \\  \\ \\ \\-.  \\  \\ \\ \\  \\/_/\\ \\/ \\ \\  __ \\  \\ \\ \\____  \\ \\  _\"-.  "
	@echo " \\ \\_\\ \\ \\_\\  \\ \\_\\  \\ \\_\\\\\"\\_ \\  \\ \\_\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\ "
	@echo "  \\/_/  \\/_/   \\/_/   \\/_/ \\/_/   \\/_/     \\/_/   \\/_/\\/_/   \\/_____/   \\/_/\\/_/ "
	@echo "                                                                                 "

clean:
	make clean -C printf
	$(RM) $(OBJS) $(OBJS_C) $(OBJS_S)

fclean: clean
	make fclean -C printf
	$(RM) $(NAME) $(SERVER)

re: fclean all
	make re -C printf

.PHONY: all clean fclean re