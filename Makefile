# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 22:41:22 by mehdidesmar       #+#    #+#              #
#    Updated: 2023/03/21 14:34:04 by mvogel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ------------------------------- VARIABLES ---------------------------------- #

NAME = minitalk

NAME_S = server
NAME_C = client

SRC_PATH = src/
SRC_LST_S = server.c
SRC_LST_C = client.c
SRC_S = $(addprefix $(SRC_PATH), $(SRC_LST_S))
SRC_C = $(addprefix $(SRC_PATH), $(SRC_LST_C))

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_PATH)

# ------------------------------- LIBFT -------------------------------------- #

LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

# ------------------------------- COMPILE ------------------------------------ #

all: $(NAME_S) $(NAME_C)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_S): $(OBJ_S) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_C): $(OBJ_C) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT) : FORCE
	$(MAKE) -C $(LIBFT_PATH)


FORCE :

# ------------------------------- CLEAN -------------------------------------- #

clean :
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_S)
	$(RM) $(OBJ_C)


fclean : clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME_S)
	$(RM) $(NAME_C)

re : fclean
	$(MAKE) all

.PHONY: all libft NAME_C NAME_S FORCE clean fclean re
 