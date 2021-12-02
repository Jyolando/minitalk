# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 19:53:09 by jyolando          #+#    #+#              #
#    Updated: 2021/12/03 00:40:32 by jyolando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = Libft/libft.a

NAME_SERVER = server

NAME_CLIENT = client

NAME_CLIENT_BONUS = client_bonus

NAME_SERVER_BONUS = server_bonus

SRC_CLIENT = mandotory/client.c \
				Libft/ft_atoi.c

SRC_SERVER = mandotory/server.c

SRC_CLIENT_BONUS = bonus/client_bonus.c \
				Libft/ft_atoi.c

SRC_SERVER_BONUS = bonus/server_bonus.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

INC = -I./include

RM = rm -f

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
				$(CC) $(FLAGS) $(OBJ_CLIENT) $(INC) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
				$(CC) $(FLAGS) $(OBJ_SERVER) $(INC) -o $(NAME_SERVER)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
				$(CC) $(FLAGS) $(OBJ_CLIENT_BONUS) $(INC) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS)
				$(CC) $(FLAGS) $(OBJ_SERVER_BONUS) $(INC) -o $(NAME_SERVER_BONUS)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

clean:
		$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean: clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean
