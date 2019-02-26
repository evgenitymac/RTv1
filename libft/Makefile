# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maheiden <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 15:44:29 by maheiden          #+#    #+#              #
#    Updated: 2019/02/04 21:51:11 by maheiden         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra

NAME = libft.a

SRC = ft_bzero.c \
	   ft_memcpy.c \
	   ft_memchr.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strcmp.c \
	   ft_strnstr.c \
	   ft_strncmp.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
           ft_lstdel.c \
	   ft_lstadd.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_atoi.c \
	   ft_atoi_base.c \
	   ft_atof.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_need_for_int_to_str.c \
	   ft_pow_int.c \
	   ft_itoa.c \
	   ft_strsplit.c \
	   ft_count_words_by_pattern_in_str.c \
	   ft_strlen_by_pattern.c \
	   ft_strdup_by_pattern.c \
	   ft_recursive_factorial.c \
	   ft_sqrt.c \
	   get_next_line.c \
	   ft_realloc.c \
	   ft_tolower_str.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
		gcc -c $(FLAG) $(SRC) -I libft.h
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
