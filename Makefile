NAME			= so_long

SRCS_DIR		= ./srcs/

FILES_COMMON	= ft_checkmap.c ft_displaymap.c ft_exitfail.c ft_fourwall.c \
				  ft_initmap.c \
				  ft_isberfile.c \
				  ft_ispathofmapvalid.c ft_onewall.c ft_parsing.c \
				  ft_printmap.c \
				  ft_readmap.c ft_strlen.c ft_threewall.c ft_twowall.c \
				  ft_whichwall.c \
				  get_next_line.c

FILES_PROG		= ft_so_long.c $(FILES_COMMON)

FILES_BONUS		=	$(FILES_COMMON)

SRCS			= $(addprefix $(SRCS_DIR),$(FILES_PROG))

SRCS_BONUS		= $(addprefix $(SRCS_DIR),$(FILES_BONUS))

ifdef BONUS_FLAG
	SRCS_COMP = $(SRCS_BONUS)
else
	SRCS_COMP = $(SRCS)
endif

OBJS			= ${SRCS_COMP:.c=.o}
OBJS_PROG		= ${SRCS:.c=.o}
OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

INCLUDES_DIR	= ./includes/

CC				= gcc

CMINILIBX		= -lmlx -framework OpenGL -framework AppKit 

CFLAGS			= -Wall -Werror -Wextra

all		: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CMINILIBX) -o $(NAME) -I $(INCLUDES_DIR)

bonus	:
	@make BONUS_FLAG=1 all

debug	: fclean
	$(CC) -g $(SRCS) $(CFLAGS) $(MINILIBX) -o $(NAME) -I $(INCLUDES_DIR)
	lldb $(NAME)

norme	:
	norminette -R CheckForbiddenSourceHeader | grep -v OK

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all
	clear

.PHONY	: all debug clean fclean re
