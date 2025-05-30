# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelissal <eelissal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 13:53:26 by eelissal          #+#    #+#              #
#    Updated: 2025/03/23 22:38:01 by eelissal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Folders

BIN		:= bin
INC		:= includes
SRC		:= src

PRINTF	:= printf
GNL		:= gnl


# Properties

NAME	= libft.a


# Commands

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf
INCLUDES	:= -I$(INC)


# Sources

HEADERS	:= $(addprefix $(INC)/,	\
				libft.h \
				ft_printf_bonus.h \
				get_next_line.h \
				)

PRINTF_SRCS:= $(addprefix $(PRINTF)/,	\
				ft_printf_bonus.c \
				ft_printf_conv_bonus.c \
				ft_printf_utils_bonus.c \
				ft_printf_utils_2_bonus.c \
				)

GNL_SRCS:= $(addprefix $(GNL)/,	\
				get_next_line.c \
				get_next_line_utils.c \
				)

SRCS := ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strcdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		$(GNL_SRCS) \
		$(PRINTF_SRCS) \

OBJS		:= $(addprefix $(BIN)/, $(SRCS:.c=.o))

all:		$(NAME)

$(BIN)/%.o:	$(SRC)/%.c $(HEADERS) Makefile
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			ar rcs $@ $?

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			find $(BIN) -type d -empty -delete

re:			fclean all

.PHONY:		all clean fclean re