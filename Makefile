# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 21:09:25 by abmahfou          #+#    #+#              #
#    Updated: 2024/05/10 12:12:16 by abmahfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

SERVER = server

BONUS = client_bonus

BONUS_S = server_bonus

CFLAGS = -Wall -Wextra -Werror

CC = cc

RM = rm -rf

HEADER = minitalk.h

HEADER_BONUS = bonus/minitalk_bonus.h

PRINTF = printf/libftprintf.a

SRC_C = client.c \
		utils.c

SRC_S = server.c \
		utils.c

SRC_BONUS = bonus/client_bonus.c \
			bonus/utils_bonus.c

SRC_BONUS_S = bonus/server_bonus.c \
			 bonus/utils_bonus.c

OBJS_C = $(SRC_C:.c=.o)

OBJS_S = $(SRC_S:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

OBJS_BONUS_S = $(SRC_BONUS_S:.c=.o)

all: $(NAME) $(SERVER)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

%.o: %.c $(HEADER_BONUS)
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

$(BONUS_S): $(OBJS_BONUS_S)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJS_BONUS_S) -o $(BONUS_S)

$(BONUS): $(OBJS_BONUS)
	make -C printf
	$(CC) $(CFLAGS) $(PRINTF) $(OBJS_BONUS) -o $(BONUS)

bonus: $(BONUS) $(BONUS_S)

clean:
	make clean -C printf
	$(RM) $(OBJS) $(OBJS_C) $(OBJS_S) $(OBJS_BONUS) $(OBJS_BONUS_S)

fclean: clean
	make fclean -C printf
	$(RM) $(NAME) $(SERVER) $(BONUS) $(BONUS_S)

re: fclean all
	make re -C printf

.PHONY: all clean fclean re