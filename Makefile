# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aweaver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 10:40:46 by aweaver           #+#    #+#              #
#    Updated: 2022/01/14 20:22:34 by aweaver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

LIBFT_PATH	=	./sources/libft/
GNL_PATH	=	./sources/get_next_line/
PRINTF_PATH	=	./sources/printf/

SRCS		=	$(addprefix $(LIBFT_PATH),\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_strlen.c			\
				ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strncmp.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strnstr.c		\
				ft_atoi.c			\
				ft_calloc.c			\
				ft_strdup.c			\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_striteri.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_count_digits.c)	\
				$(addprefix $(GNL_PATH),\
				get_next_line.c		\
				get_next_line_utils.c)\
				$(addprefix $(PRINTF_PATH),\
				ft_printf.c			\
				ft_printf_putchar.c	\
				ft_printf_putstr.c	\
				ft_printf_putnbr.c	\
				ft_printf_uhex.c	\
				ft_printf_putnbr_base.c)

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

INC			=	-I ./includes

DEP			=	$(SRCS:.c=.d)

CFLAGS		=	-MMD -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $@ $^

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:	
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

-include $(DEP)

.PHONY:		all re clean fclean
