# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 15:58:30 by ohakola           #+#    #+#              #
#    Updated: 2020/02/14 15:12:01 by ohakola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fractol
LIBFT = ./lib/libft
LIBMLX = ./lib/libmlx
DIR_SRC = src
DIR_OBJ = temp
HEADERS = incl
FLAGS = -Wall -Wextra -Werror -O2
LIBMLXFLAGS = -I$(LIBMLX) -L$(LIBMLX) -lmlx -framework OpenGL -framework Appkit
LIBFTFLAGS = -L$(LIBFT) -lft
THREADFLAGS = -lpthread
SOURCES = main.c \
			log.c \
			args.c \
			scene/scene.c \
			scene/select.c \
			scene/thread.c \
			draw/pixel.c \
			draw/draw.c \
			events/keys.c \
			events/mouse.c \
			events/loop.c \
			events/exit.c \
			fractals/mandelbrot.c \
			fractals/julia.c \
			fractals/phoenix.c \
			fractals/julia_mod.c \
			fractals/julia_n.c \
			fractals/burning_ship.c \
			fractals/bird_of_prey.c \
			fractals/mandelbrot_n.c \
			fractals/utils.c \
			fractals/utils2.c \
			fractals/utils3.c \
			fractals/colors.c \
			fractals/params.c \
			fractals/params2.c \
			ui/ui.c \
			ui/utils.c \
			ui/guide.c

SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))

all: $(DIR_OBJ) $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(LIBMLX)
	$(CC) $(FLAGS) $(LIBFTFLAGS) $(LIBMLXFLAGS) $(THREADFLAGS) -o $@ $^

$(DIR_OBJ):
	@mkdir -p temp
	@mkdir -p temp/scene
	@mkdir -p temp/draw
	@mkdir -p temp/ui
	@mkdir -p temp/events
	@mkdir -p temp/fractals

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADERS)/$(NAME).h
	@$(CC) $(FLAGS) -I $(HEADERS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)
	@make -C $(LIBFT) clean
	@make -C $(LIBMLX) clean
	@/bin/rm -rf $(DIR_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(LIBMLX) fclean

norm:
	norminette $(HEADERS) $(LIBFT) $(DIR_SRC)

re: fclean all

.PHONY: all, $(DIR_OBJ), clean, fclean, norm
