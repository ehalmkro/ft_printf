# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehalmkro <ehalmkro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 16:28:01 by ehalmkro          #+#    #+#              #
#    Updated: 2020/04/13 16:57:44 by ehalmkro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR = src/
SRC_FILES = ft_printf.c handle_integer.c handle_params.c output.c handle_hex.c \
            handle_string.c handle_char.c handle_float.c
INCLUDES = include/
SOURCES = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIB = Libft/
FLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRC_FILES:.c=.o)

all: $(NAME)
$(NAME):
				@make -C $(LIB)
				@cp $(LIB)/Libft.a ./$(NAME)
				@gcc $(FLAGS) -c $(SOURCES)
				ar rc $(NAME) $(OBJECTS)
				@ranlib $(NAME)
clean:
				@rm -f $(OBJECTS)
				@make -C $(LIB) clean
fclean: clean
				@rm -f $(NAME)
				@make -C $(LIB) fclean
re: fclean all
