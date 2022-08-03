SRCS = cub3d.c\
		draw.c\
		draw2.c\
		events.c\
		ft_split.c\
		ft_strtrim.c\
		ft_substr.c\
		get_next_line.c\
		get_next_line_utils.c\
		map_info.c\
		my_func1.c\
		my_func2.c\
		myfunc3.c\
		myfunc4.c\
		ray_cast.c\
		readingfile.c\
		save.c\
		myfunc5.c\
		errors.c\
		myfunc6.c\
		
INCL = -INCLUDES/

OBJS = ${SRCS:.c=.o}

NAME = cub3D

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : ${OBJS}
		@gcc $(FLAGS)  -I/usr/local/include ${OBJS} -g -o$(NAME) -L/usr/local/lib -lmlx -framework Opengl -framework APPKIT 
.c.o : ${SRCS}
		@gcc $(FLAGS) -c ${INCL} $< -o ${<:.c=.o}
clean :
		@rm -f ${OBJS}
fclean : clean
		@rm -f $(NAME)
re : fclean
		make all