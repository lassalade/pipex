# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 14:50:34 by eelissal          #+#    #+#              #
#    Updated: 2025/03/24 23:32:16 by eelissal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = pipex


# FOLDERS

BIN		:= bin
INC		:= includes
SRC		:= src
LIBFT_DIR := libft

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM			:= rm -rf
INCLUDES	:= -I$(INC) -I$(addprefix $(LIBFT_DIR)/, $(INC))


# SOURCES

SRCS	:=	pipex.c \
			pipex_pathname.c \
			pipex_utils.c

OBJS	:= $(addprefix $(BIN)/, $(SRCS:.c=.o))

HEADERS	:= $(addprefix $(INC)/, pipex.h \
				)

LIBFT	:= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
			@make -C $(LIBFT_DIR)

$(BIN)/%.o: $(SRC)/%.c $(HEADERS)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) Makefile
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

clean:
			$(RM) $(OBJS)
			@make -C $(LIBFT_DIR) clean

fclean: clean
			$(RM) $(NAME)
			@make -C $(LIBFT_DIR) fclean
			find $(BIN) -type d -empty -delete

re: fclean all

.PHONY: all clean fclean re
