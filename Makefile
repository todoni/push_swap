# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 15:38:21 by sohan             #+#    #+#              #
#    Updated: 2022/03/11 15:39:01 by sohan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES_DIR = ./includes/
LIBFT_INC_DIR = ./libft/
SOURCE_DIR = ./sources/
OBJECT_DIR = objects
FILES = \
		deque\
		heap\
		operations\
		push_swap_tuto\
		parse\
		utils\
		push_swap_under5\
		atoi_safe\
		push_swap

vpath %.c $(SOURCE_DIR)

SRC = $(addprefix $(SOURCE_DIR), $(addsuffix .c, $(FILES)))
OBJECTS = $(addprefix $(OBJECT_DIR)/, $(addsuffix .o, $(FILES)))

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft

NAME = push_swap
LIBFT = $(addprefix $(LIBFT_INC_DIR), libft.a)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECT_DIR) $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCLUDES_DIR) $(OBJECTS) -o $@

$(OBJECT_DIR):
	@echo make object folder
	@mkdir -p $(OBJECT_DIR)

$(OBJECT_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_INC_DIR) -c $< -o $@

$(LIBFT):
	@echo "make libft"
	@make -C libft/

clean:
	rm -rf $(OBJECT_DIR)
	@make -C $(LIBFT_INC_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_INC_DIR) fclean

re : fclean all

.PHONY: all clean fclean re
