# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:35:35 by lsaumon           #+#    #+#              #
#    Updated: 2024/03/09 03:11:49 by lsaumon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

# =================================== SOURCES ==================================

SRCS =	srcs/str/ft_atoi.c \
		srcs/mems/ft_bzero.c \
		srcs/mems/ft_calloc.c \
		srcs/str/ft_isalnum.c \
		srcs/str/ft_isalpha.c \
		srcs/str/ft_isascii.c \
		srcs/str/ft_isdigit.c \
		srcs/str/ft_isprint.c \
		srcs/mems/ft_memchr.c \
		srcs/mems/ft_memcmp.c \
		srcs/mems/ft_memcpy.c \
		srcs/mems/ft_memmove.c \
		srcs/mems/ft_memset.c \
		srcs/str/ft_strchr.c \
		srcs/str/ft_strdup.c \
		srcs/str/ft_strlcat.c \
		srcs/str/ft_strlcpy.c \
		srcs/str/ft_strlen.c \
		srcs/str/ft_strncmp.c \
		srcs/str/ft_strnstr.c \
		srcs/str/ft_strrchr.c \
		srcs/str/ft_tolower.c \
		srcs/str/ft_toupper.c \
		srcs/str/ft_substr.c \
		srcs/str/ft_strjoin.c \
		srcs/str/ft_strtrim.c \
		srcs/str/ft_split.c \
		srcs/str/ft_itoa.c \
		srcs/str/ft_strmapi.c \
		srcs/str/ft_striteri.c \
		srcs/put/ft_putchar_fd.c \
		srcs/put/ft_putstr_fd.c \
		srcs/put/ft_putendl_fd.c \
		srcs/put/ft_putnbr_fd.c \
		srcs/list/ft_lstnew_bonus.c \
		srcs/list/ft_lstadd_front_bonus.c \
		srcs/list/ft_lstsize_bonus.c \
		srcs/list/ft_lstadd_back_bonus.c \
		srcs/list/ft_lstdelone_bonus.c \
		srcs/list/ft_lstclear_bonus.c \
		srcs/list/ft_lstiter_bonus.c \
		srcs/list/ft_lstmap_bonus.c \
		srcs/list/ft_lstlast_bonus.c \
		srcs/ft_printf/ft_printf_utils.c \
		srcs/ft_printf/ft_printf.c \
		srcs/ft_printf/ft_printnbr.c \
		srcs/get_next_line/get_next_line.c \
		srcs/get_next_line/get_next_line_utils.c \

OBJ_DIR		:= .objs
OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# =================================== FLAGS ====================================

CC =	cc
FLAGS =	-Wall -Wextra -g3 -fsanitize=address -Werror
RM =	rm -rf
AR =	ar rcs

$(OBJ_DIR)/%.o :%.c
	@mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) -c $< -o $@

# =================================== COLORS ===================================

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN		:=	\033[1;36m

# =================================== COMPILATION ==============================

all:	${NAME}

$(NAME):	$(OBJS) 
	@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@ $(AR) $(NAME) $(OBJS)
	@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"

# =================================== RULES ====================================

clean:

	@ $(RM) $(OBJ_DIR)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean

	@ $(RM) $(NAME) $(RM)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all bonus clean fclean re