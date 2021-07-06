NAME	=	miniRT

SRCS	=	main.c			\
			parcer.c		\
			utils_parser.c	\
			utils_parser2.c	\
			cam_and_light.c	\
			intersects.c	\
			funcs_vectors.c	\
			RT.c			\
			figure.c		\
			color_pixel.c	\
			my_math.c		\
			ft_split_rt.c	\
			utils.c			\
			utils3.c		\
			gnl/get_next_line.c	\
			gnl/get_next_line_utils.c

HEADER	=	miniRT.h\

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
			gcc -g $(SRCS) -lmlx -framework OpenGL -framework AppKit libmlx.dylib libftprintf.a libft.a -o $(NAME)

libft	:
			cd libft
			make
			mv libft.a ../
clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean clean all

.PHONY	: all clean fclean re