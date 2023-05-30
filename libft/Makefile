# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:20:33 by mvogel            #+#    #+#              #
#    Updated: 2023/03/21 13:52:34 by mvogel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rc

SRC = ft_atoi.c \
	ft_atoi_long.c \
	ft_isalpha.c \
	ft_isprint.c \
    ft_memcpy.c \
    ft_strlcpy.c \
    ft_strnstr.c \
    ft_toupper.c \
    ft_bzero.c \
    ft_isascii.c \
    ft_memchr.c \
    ft_memmove.c \
    ft_strchr.c \
    ft_strlen.c \
    ft_strrchr.c \
    ft_isalnum.c \
    ft_isdigit.c \
    ft_memcmp.c \
    ft_memset.c \
    ft_strlcat.c \
    ft_strncmp.c \
    ft_tolower.c \
    ft_strdup.c \
    ft_calloc.c \
    ft_substr.c \
    ft_strjoin.c \
    ft_strtrim.c \
    ft_split.c \
    ft_itoa.c \
    ft_strmapi.c \
    ft_striteri.c \
    ft_putchar_fd.c \
    ft_putstr_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_printf.c \
	ft_printf_utils.c \
	get_next_line.c \
	ft_free_tab.c \
	ft_realloc.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
