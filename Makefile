NAME			= so_long

LIB_DIR			= ./srcs/

LIB_SRC			= ft_so_long.c ft_checkmap.c ft_exitfail.c ft_isberfile.c \
				  ft_ispathofmapvalid.c ft_parsing.c ft_readmap.c ft_strlen.c \
				  get_next_line.c

SRCS			= $(addprefix $(LIB_DIR),$(LIB_SRC))

OBJS			= ${SRCS:.c=.o}

INCLUDES_DIR	= ./includes/

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra

CMINILIBX		= -lmlx -framework OpenGL -framework AppKit 

all		: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME) -I $(INCLUDES_DIR)

debug : fclean
	$(CC) -g $(SRCS) $(CFLAGS) -o $(NAME) -I $(INCLUDES_DIR)
	lldb $(NAME)

clean :
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all
	clear

.PHONY	: all debug clean fclean re
