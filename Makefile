NAME	=	miniRT

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

HEADER	=	srcs/miniRT.h\

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
			gcc -g -Lmlx -lmlx -framework OpenGL -framework AppKit libmlx.dylib libftprintf.a libft.a $(SRCS) -o $(NAME)
			# gcc -g -Lmlx -lmlx -framework OpenGL -framework AppKit libmlx.a -Llibft -lft $(SRCS) -o $(NAME)
# -lftprintf libftprintf.a

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