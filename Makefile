NAME	=	miniRT
LIBFT	=	libft/libft.a
MLX		=	mlx1/libmlx.dylib

SRCS	=	srcs/main.c			\
			srcs/parcer.c		\
			srcs/utils_parser.c	\
			srcs/utils_parser2.c	\
			srcs/cam_and_light.c	\
			srcs/intersects.c	\
			srcs/funcs_vectors.c	\
			srcs/RT.c			\
			srcs/figure.c		\
			srcs/color_pixel.c	\
			srcs/my_math.c		\
			srcs/ft_split_rt.c	\
			srcs/utils.c			\
			srcs/utils3.c		\
			gnl/get_next_line.c	\
			gnl/get_next_line_utils.c

HEADER	=	srcs/miniRT.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-I. #-Wall -Wextra -Werror

RM		=	rm -f

all		:	$(LIBFT) $(MLX) $(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
#			 gcc -g -Lmlx -lmlx -framework OpenGL -framework AppKit libmlx.dylib libftprintf.a libft.a $(SRCS) -o $(NAME)
			gcc -g $(MLX) -framework OpenGL -framework AppKit -Llibft -lft -o $(NAME) $(OBJ)
# -lftprintf libftprintf.a

$(LIBFT) :
			$(MAKE) -C libft/

$(MLX) :
			$(MAKE) -C mlx1/
			cp $(MLX) ./

clean	:
			$(MAKE) clean -C libft/
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)
			$(MAKE) fclean -C libft/
			$(MAKE) clean -C mlx1/

re		:	fclean clean all

.PHONY	: all clean fclean re