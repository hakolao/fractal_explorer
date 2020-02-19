# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 15:58:30 by ohakola           #+#    #+#              #
#    Updated: 2020/02/20 00:02:25 by ohakola          ###   ########.fr        #
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
			fractals/escape_time/mandelbrot.c \
			fractals/escape_time/julia.c \
			fractals/escape_time/burning_ship.c \
			fractals/escape_time/mandelbrot_n.c \
			fractals/escape_time/julia_n.c \
			fractals/escape_time/bird_of_prey.c \
			fractals/escape_time/julia_mod.c \
			fractals/escape_time/phoenix_mod.c \
			fractals/escape_time/burning_julia.c \
			fractals/mandelbrot.c \
			fractals/julia.c \
			fractals/utils/interact.c \
			fractals/utils/move.c \
			fractals/utils/scale.c \
			fractals/utils/image.c \
			fractals/utils/colors.c \
			fractals/params/mandelbrot.c \
			fractals/params/julia.c \
			fractals/params/burning_ship.c \
			fractals/params/mandelbrot_n.c \
			fractals/params/julia_n.c \
			fractals/params/bird_of_prey.c \
			fractals/params/julia_mod.c \
			fractals/params/phoenix_mod.c \
			fractals/params/burning_julia.c \
			fractals/params/copy.c \
			complex/complex.c \
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
	@mkdir -p temp/complex
	@mkdir -p temp/fractals
	@mkdir -p temp/fractals/utils
	@mkdir -p temp/fractals/params
	@mkdir -p temp/fractals/escape_time

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
