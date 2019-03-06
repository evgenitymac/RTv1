# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 14:33:53 by jlucas-l          #+#    #+#              #
#    Updated: 2019/03/04 15:56:50 by jlucas-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC_D = $(addprefix ./srcs/, $(SRCS))
VECTOR_D = $(addprefix ./vectorlib/, $(VECTOR))
OBJ_D = objs
INC = -I ./libft/ -I ./includes -I ./SDL2/SDL2.framework/Headers -I ./vectorlib/
LIB = -L ./libft/ -lft
SDL = -F ./SDL2/ -framework SDL2 

GCCFLAGS = -Wall -Wextra -Werror
SRCS = main.c \
	   additional.c \
	   event.c \
	   image.c \
	   intersection.c \
	   light_calculating.c \
	   lightning.c \
	   parse_additional.c \
	   parse_additional_helper.c \
	   parse_additional_init.c \
	   parser.c \
	   render.c

VECTOR = change_basis.c \
		 cross_product.c \
		 dot_product.c \
		 identity_matrix.c \
		 matrix_multiply.c \
		 matrix_scalar.c \
		 matrix_sum.c \
		 matrix_vector_multiply.c \
		 point_in_triangle_2d.c \
		 rotation_matrix.c \
		 rotation_vector_by_x_z.c \
		 scale_matrix.c \
		 translation_matrix.c \
		 vector_length.c \
		 vector_matrix_multiply.c \
		 vector_normalize.c \
		 vector_scalar_multipy.c \
		 vector_sub.c \
		 vector_sum.c \
		 vectors_angle.c

OBJS = $(addprefix $(OBJ_D)/,$(SRCS:.c=.o))
OBJS2 = $(addprefix $(OBJ_D)/,$(VECTOR:.c=.o))

all: $(NAME)

$(NAME):
		make -C ./libft
		gcc $(GCCFLAGS) -c $(SRC_D) $(VECTOR_D) $(INC)
		mkdir -p $(OBJ_D) && mv $(SRCS:.c=.o) ./$(OBJ_D)/ && mv $(VECTOR:.c=.o) ./$(OBJ_D)/
		gcc $(GCCFLAGS) -o $(NAME) $(OBJS) $(OBJS2) $(SDL) $(LIB) $(INC)

clean:
		make clean -C ./libft
		rm -rf $(OBJ_D)

fclean: clean
		make fclean -C ./libft
		rm -rf $(NAME)

re: fclean all
