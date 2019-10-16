# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmousset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 10:12:56 by jmousset          #+#    #+#              #
#    Updated: 2019/10/16 15:45:11 by jmousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m

NAME = fractol

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIB_PATH = ./libft/

LIB = ./libft/libft.a

MLX_PATH = ./minilibx/

HDR = fractol.h

SRCS = main.c\
	   fractol.c\
	   fractals.c\
	   fractals_2.c\
	   draw.c\
	   keyboard_events.c\
	   keyboard_events_2.c\
	   mouse_events.c\
	   menu.c

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(LIB) $(OBJS) Makefile $(HDR)
	@gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIB) -L $(MLX_PATH) $(MLX_FLAGS)
	@echo "$(YELLOW)./$(NAME) $(GREEN)ready   ✅ "

-include $(DEPS)

./%.o : ./%.c Makefile $(HDR)
	@gcc $(FLAGS) -I $(LIB_PATH) -MMD -MP -c $< -o $@

$(LIB) : force
	@make -C $(LIB_PATH)

force :

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW).o        $(RED)deleted 💯 "
	@rm -f $(DEPS)
	@echo "$(YELLOW).d        $(RED)deleted 💯 "
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(YELLOW)./$(NAME) $(RED)deleted 💯 "

re: fclean all

.SILENT:

.PHONY: all clean fclean re
