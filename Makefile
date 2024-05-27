# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 21:09:25 by abmahfou          #+#    #+#              #
#    Updated: 2024/05/27 10:35:29 by abmahfou         ###   ########.fr        #
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

$(NAME): $(OBJS_C) $(OBJS_S)
	make -C printf
	$(CC) $(CFLAGS) $(PRINTF) $(OBJS_C) -o $(NAME) && $(CC) $(CFLAGS) $(PRINTF) $(OBJS_S) -o $(SERVER)

$(BONUS): $(OBJS_BONUS) $(OBJS_BONUS_S)
	make -C printf
	$(CC) $(CFLAGS) $(PRINTF) $(OBJS_BONUS) -o $(BONUS) && $(CC) $(CFLAGS) $(PRINTF) $(OBJS_BONUS_S) -o $(BONUS_S)

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