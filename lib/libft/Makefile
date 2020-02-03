# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 14:43:04 by ohakola           #+#    #+#              #
#    Updated: 2020/02/01 16:48:00 by ohakola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME = libft.a
DIR_SRC = ./
DIR_OBJ = temp
SOURCES = ft_atoi.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memdel.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_strstr.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isupper.c \
		ft_putchar.c \
		ft_putstr_fd.c \
		ft_strncmp.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_islower.c \
		ft_memalloc.c \
		ft_putchar_fd.c \
		ft_strcmp.c \
		ft_strnstr.c \
		ft_toupper.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memset.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_itoa_base.c \
		ft_itoa.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strsplit_lst.c \
		ft_lstfold.c \
		ft_lstappend.c \
		ft_realloc.c \
		get_next_line.c \
		ft_isqrt.c \
		ft_sqrt.c \
		ft_strfill.c \
		ft_lstlen.c \
		ft_lmap_int.c \
		ft_lmap_double.c \
		ft_max.c \
		ft_abs.c \
		ft_bzero.c
SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))
HEADERS = ./
FLAGS = -Wall -Wextra -Werror

all: $(DIR_OBJ) $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

$(DIR_OBJ):
	@mkdir -p temp

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADERS)/libft.h
	@$(CC) $(FLAGS) -I $(HEADERS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf $(DIR_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, $(DIR_OBJ), clean, fclean, re
