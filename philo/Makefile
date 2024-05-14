# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 09:08:04 by ubuntu            #+#    #+#              #
#    Updated: 2024/05/14 14:39:23 by vvaudain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Setup
NAME 		:=	philosophers
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g3

# Valgrind
VAL_FLAGS	:=	--leak-check=full --show-leak-kinds=all --track-origins=yes

# Directories
BIN_DIR 	:=	./bin
INC_DIR 	:=	./inc

SRC_DIR		:=	./srcs

# Colors
DEF_COLOR	:=	\033[0;39m
GREEN 		:=	\033[0;92m
CYAN 		:=	\033[0;96m

# Sources and Objects
SRC			:=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/utils.c

# $(SRC_DIR)/free.c \
# $(SRC_DIR)/init.c \
# $(SRC_DIR)/parsing_utils.c \
# $(SRC_DIR)/parsing.c \
# $(SRC_DIR)/remove.c \
# $(SRC_DIR)/simul_utils.c \
# $(SRC_DIR)/simulation.c \
# $(SRC_DIR)/routine_func.c \
# $(SRC_DIR)/utils.c
				


OBJ			:=	$(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

# Default make
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -I $(INC_DIR) $(OBJ) -o $(NAME)
	@echo "$(GREEN)philosophers compiled !$(DEF_COLOR)"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Clean Objects
clean:
	rm -rf $(BIN_DIR)
	@echo "$(CYAN)binary files cleaned !$(DEF_COLOR)"

# Full Clean, Objects and Binaries
fclean: clean
	rm -f $(NAME)
	@echo "$(CYAN)exec files cleaned !$(DEF_COLOR)"

# Remake
re: fclean $(NAME)
	@echo "$(GREEN)Cleaned and rebuilt everything !$(DEF_COLOR)"

# Norminette
norm:
	@norminette $(SRC) $(INC_DIR)/*.h

# Valgrind
val: $(NAME)
	@valgrind $(VAL_FLAGS) ./$(NAME)

# Non-File Targets
.PHONY:	all clean fclean re norm val