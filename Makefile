# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moguy <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 05:16:04 by moguy             #+#    #+#              #
#    Updated: 2019/07/21 07:00:03 by moguy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF = \033[0m
GRA = \033[1m
SOU = \033[4m
BLI = \033[5m
BLA = \033[30m
RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
PUR = \033[35m
CYA = \033[36m
WHI = \033[37m
ORG = \033[1;31m

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRCS_LIB = ft_power.c \
		   ft_abs.c \
		   ft_memalloc.c \
		   ft_putendl_fd.c \
		   ft_putstr_fd.c \
		   ft_strchr.c \
		   ft_strcmp.c \
		   ft_putstr.c \
		   ft_strdel.c \
		   ft_strlen.c \
		   ft_strrev.c \
		   ft_memdel.c \
		   ft_memset.c \
		   ft_putendl.c \
		   ft_putnbr.c \
		   ft_strnew.c \
		   ft_strcat.c \
		   ft_bzero.c \
		   ft_strdup.c \
		   ft_putchar.c \
		   ft_strcpy.c \
		   ft_isdigit.c

SRCS_NAME =	ft_printf.c \
			field_accuracy.c \
			display.c \
			dispatcher.c \
			option.c \
			cast.c \
			convertion_bdioux.c \
			convertion_cspmodulo.c \
			convertion_f.c \
			get_option.c \
			get_cast_convertion.c \
			init.c \
			error_fonction_lib.c

SRCS_PATH = srcs/

LIB_PATH = libft/

HDR_NAME = ft_printf.h

HDR_PATH = includes/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

HDR = $(addprefix $(HDR_PATH), $(HDR_NAME))

SRCS2 = $(addprefix $(LIB_PATH), $(SRCS_LIB))

OBJ = $(SRCS:.c=.o)

OBJ2 = $(SRCS2:.c=.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ2)
			@ar rc $(NAME) $(OBJ) $(OBJ2)
			@ranlib $(NAME)
			@echo "$(ORG)Make libftprintf$(DEF) : $(GRE)Done!$(DEF)"

%.o : %.c $(HDR)
			@$(CC) $(CFLAGS) -c $< -o $@

clean :
			@rm -rf $(OBJ)
			@make -C $(LIB_PATH) clean
			@echo "$(ORG)libftprintf clean$(DEF) : $(GRE)Done!$(DEF)"

fclean : clean
			@rm -rf $(NAME)
			@make -C $(LIB_PATH) fclean
			@echo "$(ORG)libftprintf fclean$(DEF) : $(GRE)Done!$(DEF)"

re : fclean all
