# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 21:25:23 by anemesis          #+#    #+#              #
#    Updated: 2022/03/30 12:53:56 by anemesis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1		=	server

NAME_2		=	client

NAME_B_1	=	server_b

NAME_B_2	=	client_b

HEADER		=	./inc/minitalk.h

HEADER_B	=	./inc/minitalk_bonus.h

OBJDIR		=	obj

OBJDIR_B	=	obj_bonus

SRC			=	$(wildcard ./src/*.c)

SRC_B		=	$(wildcard ./src_bonus/*.c)

OBJ_1		=	$(patsubst %./obj/client.o,%,$(SRC:./src/%.c=./obj/%.o))

OBJ_2		=	$(patsubst %./obj/server.o,%,$(SRC:./src/%.c=./obj/%.o))

OBJ_B_1		=	$(patsubst %./obj/server.o,%,$(OBJ_1)) \
				$(patsubst %./obj_bonus/client_bonus.o,%,$(SRC_B:./src_bonus/%.c=./obj_bonus/%.o))

OBJ_B_2		=	$(patsubst %./obj/client.o,%,$(OBJ_2)) \
				$(patsubst %./obj_bonus/server_bonus.o,%,$(SRC_B:./src_bonus/%.c=./obj_bonus/%.o))

CC			=	gcc

CFLAGS 		=	-Wall -Wextra -Werror

INC			=	-I ./inc -I ./libft

LIB			=	-L ./libft -lft

all: lib $(NAME_1) $(NAME_2)

lib:
	@make -C ./libft

$(NAME_1): $(OBJ_1) $(HEADER)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ_1) -o $(NAME_1)

$(NAME_2): $(OBJ_2) $(HEADER)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ_2) -o $(NAME_2)

./$(OBJDIR)/%.o: ./src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus: lib $(NAME_B_1) $(NAME_B_2)
	
$(NAME_B_1): $(OBJ_B_1) $(HEADER_B)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ_B_1) -o $(NAME_B_1)

$(NAME_B_2): $(OBJ_B_2) $(HEADER_B)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ_B_2) -o $(NAME_B_2)

./$(OBJDIR_B)/%.o: ./src_bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf obj obj_bonus
	@make clean -C ./libft

fclean: clean
	@rm -rf $(NAME_1) $(NAME_B_1) $(NAME_2) $(NAME_B_2)
	@make fclean -C ./libft

re: fclean all bonus

.PHONY: bonus all obj obj_bonus clean fclean re