# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 20:24:51 by anemesis          #+#    #+#              #
#    Updated: 2022/03/13 14:49:37 by anemesis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a\

HEADER	=	libft.h\

SRC		=	$(wildcard ./src/*.c)

OBJ		=	$(SRC:./src/%.c=./obj/%.o)

CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -I $(HEADER)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rcs $(NAME) $?

obj/%.o: src/%.c | obj
	@$(CC) $(CFLAGS) -c $< -o $@

obj:
	@mkdir -p obj

clean:
	@$(RM) obj

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re