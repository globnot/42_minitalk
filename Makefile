# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborda <aborda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 10:21:17 by aborda            #+#    #+#              #
#    Updated: 2026/01/15 14:20:37 by aborda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
RESET		= \033[0m

# Project
CLIENT_NAME	= client
SERVER_NAME	= server
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -Iincludes -I./libft/includes

# Librairy
LIBFT 		= ./libft/libft.a

# Directories
OBJ_DIR		= objs

# Sources
SRCS_CLIENT	= srcs/client.c
SRCS_SERVER	= srcs/server.c

# Objects
OBJS_CLIENT	= $(OBJ_DIR)/client.o
OBJS_SERVER	= $(OBJ_DIR)/server.o 

# Rules
all: $(CLIENT_NAME) $(SERVER_NAME)

$(LIBFT):
	@make -C libft

$(OBJS_CLIENT): $(SRCS_CLIENT)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)✓$(RESET) Compiled: $(CYAN)$<$(RESET)"

$(OBJS_SERVER): $(SRCS_SERVER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)✓$(RESET) Compiled: $(CYAN)$<$(RESET)"

$(CLIENT_NAME): $(LIBFT) $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(CLIENT_NAME)
	@echo "$(GREEN)==========================================$(RESET)"
	@echo "$(GREEN)✓ $(CLIENT_NAME) created successfully!$(RESET)"
	@echo "$(GREEN)==========================================$(RESET)"

$(SERVER_NAME): $(LIBFT) $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(SERVER_NAME)
	@echo "$(GREEN)==========================================$(RESET)"
	@echo "$(GREEN)✓ $(SERVER_NAME) created successfully!$(RESET)"
	@echo "$(GREEN)==========================================$(RESET)"

clean:
	@make clean -C libft
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)✓ Object files removed$(RESET)"

fclean: clean
	@make fclean -C libft
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)
	@echo "$(YELLOW)✓ $(NAME) client & server removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
