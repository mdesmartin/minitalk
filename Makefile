# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehdidesmartin <mehdidesmartin@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 00:36:44 by mehdidesmar       #+#    #+#              #
#    Updated: 2023/03/06 12:45:09 by mehdidesmar      ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ------------------------------- VARIABLES ---------------------------------- #

NAME = minitalk

CLIENT_NAME = client

SERVER_NAME = server

HDR_PATH = include/

HDR_LST = minitalk.h

HDR = $(addprefix $(HDR_PATH), $(HDR_LST))

SRC_PATH = src/

CLIENT_SRC = client.c

SERVER_SRC = server.c

SRC_CLIENT = $(addprefix $(SRC_PATH), $(CLIENT_SRC))

SRC_SERVER = $(addprefix $(SRC_PATH), $(SERVER_SRC))


CLIENT_OBJ = $(SRC_CLIENT:.c=.o)

SERVER_OBJ = $(SRC_SERVER:.c=.o)


OBJ_CLIENT = $(addprefix $(SRC_PATH), $(CLIENT_OBJ))

OBJ_SERVER = $(addprefix $(SRC_PATH), $(SERVER_OBJ))

LIBFT_PATH = libft/

LIBFT_NAME = libft.a

LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))


CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_PATH) -I $(HDR_PATH)

# ------------------------------- COMPILE ------------------------------------ #

all: $(NAME)

%.o : %.c Makefile $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): client server

client : $(LIBFT) $(CLIENT_OBJ) 
		$(CC) $(CFLAGS) $^ -o $(CLIENT_NAME)

server : $(LIBFT) $(SERVER_OBJ)
		$(CC) $(CFLAGS) $^ -o $(SERVER_NAME)

$(LIBFT) : FORCE
	$(MAKE) -C $(LIBFT_PATH)

FORCE :

# ------------------------------- CLEAN -------------------------------------- #

clean :
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_CLIENT)
	$(RM) $(OBJ_SERVER)

fclean : clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(CLIENT_NAME)
	$(RM) $(SERVER_NAME)

re : fclean
	$(MAKE) all

.PHONY: all libft client server FORCE clean fclean re
 