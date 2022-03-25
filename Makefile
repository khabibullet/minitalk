# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 21:25:23 by anemesis          #+#    #+#              #
#    Updated: 2022/03/19 15:56:25 by anemesis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_B		=	checker

HEADER		=	./inc/push_swap.h

HEADER_B	=	./inc/push_swap_bonus.h

SRC			=	$(wildcard ./src/*.c)

SRC_B		=	$(wildcard ./src_bonus/*.c)

OBJ			=	$(SRC:./src/%.c=./obj/%.o)

OBJ_B		=	$(patsubst %./obj/main.o,%,$(OBJ)) $(SRC_B:./src_bonus/%.c=./obj_bonus/%.o)

CC			=	gcc

CFLAGS 		=	-Wall -Wextra -Werror

INC			=	-I ./inc -I ./libft

LIB			=	-L ./libft -lft

all: lib $(NAME)

lib:
	@make -C ./libft

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ) -o $(NAME)

./obj/%.o: ./src/%.c | obj
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj:
	@mkdir -p obj

bonus: all $(NAME_B)
	
$(NAME_B): $(OBJ_B) $(HEADER_B)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ_B) -o $(NAME_B)

./obj_bonus/%.o: ./src_bonus/%.c | obj_bonus
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj_bonus:
	@mkdir -p obj_bonus

clean:
	@rm -rf obj obj_bonus
	@make clean -C ./libft

fclean: clean
	@rm -rf $(NAME) $(NAME_B)
	@make fclean -C ./libft

re: fclean all bonus

.PHONY: bonus all obj clean fclean re