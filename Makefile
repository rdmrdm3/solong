NAME			= so_long

NAME_BONUS		= so_long_bonus

SRCS_DIR		= ./srcs/

FILES_COMMON	= ft_changedoor.c ft_closegame.c ft_displaymap.c ft_fourwall.c \
				  ft_initmap.c ft_inputmap.c ft_inputspot.c \
				  ft_isberfile.c ft_ispathofmapvalid.c ft_freemap.c \
				  ft_ghostfirstmove.c \
				  ft_onewall.c ft_pacmove.c ft_printmap.c \
				  ft_printmaze.c ft_putnbmove.c ft_readmap.c ft_strlen.c \
				  ft_threewall.c ft_twowall.c ft_whichwall.c \
				  get_next_line.c

FILES_PROG		= ft_checkmap.c ft_exitfail.c ft_game.c \
				ft_parsing.c ft_presskey.c ft_so_long.c \
				$(FILES_COMMON)

FILES_BONUS		= ft_checkmap_bonus.c ft_exitfail_bonus.c ft_game_bonus.c \
				ft_ghostmove.c ft_itoa.c \
				ft_parsing_bonus.c \
				ft_presskey_bonus.c ft_so_long_bonus.c $(FILES_COMMON)

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

CMINILIBX		= -L./mlx -lmlx -framework OpenGL -framework AppKit 

CFLAGS			= -Wall -Werror -Wextra 
// -g -fsanitize=address

all		: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CMINILIBX) -o $(NAME) -I $(INCLUDES_DIR)

bonus	:
	@make BONUS_FLAG=1 all

debug	: fclean
	$(CC) -g $(SRCS) $(CFLAGS) $(CMINILIBX) -o $(NAME)_debug -I $(INCLUDES_DIR)
	lldb $(NAME)_debug

norme	:
	cd srcs/
	norminette -R CheckForbiddenSourceHeader | grep -v OK

run		: fclean all
	@./so_long maps/map01.ber

test	:
	@echo "########### test without argument ##################################"
	@./so_long
	@echo "########### test with 3 arguments ##################################"
	@./so_long a d h
	@echo "########### test with invalid map path #############################"
	@./so_long maps/nomaphere.ber
	@echo "########### test with a non .ber file ##############################"
	@./so_long maps/map.map
	@echo "########### test 1 with a non rectangular map ######################"
	@./so_long maps/notrec1.ber
	@echo "########### test 2 with a non rectangular map ######################"
	@./so_long maps/notrec2.ber
	@echo "########### test 3 with a non rectangular map ######################"
	@./so_long maps/notrec3.ber
	@echo "########### test with 0 player on the map ##########################"
	@./so_long maps/map0player.ber
	@echo "########### test with 2 players on the map #########################"
	@./so_long maps/map2players.ber
	@echo "########### test with 0 collectible on the map #####################"
	@./so_long maps/nocollectible.ber
	@echo "########### test with 0 exit on the map ############################"
	@./so_long maps/noexit.ber
	@echo "########### test with 2 exit on the map ############################"
	@./so_long maps/twoexit.ber
	@echo "########### test with 1 ghost on the map ###########################"
	@./so_long maps/mapwithghost.ber
	@echo "########### test 1 with incomplete walls around on the map #########"
	@./so_long maps/mapcorner1.ber
	@echo "########### test 2 with incomplete walls around on the map #########"
	@./so_long maps/mapcorner2.ber
	@echo "########### test 3 with incomplete walls around on the map #########"
	@./so_long maps/mapcorner3.ber
	@echo "########### test 4 with incomplete walls around on the map #########"
	@./so_long maps/mapcorner4.ber
	@echo "########### test 5 with incomplete walls around on the map #########"
	@./so_long maps/mapcorner5.ber
	@echo "########### test 6 with incomplete walls around on the map #########"
	@./so_long maps/mapcorner6.ber

clean	:
	rm -f $(OBJS_PROG)
	rm -f $(OBJS_BONUS)

fclean	: clean
	rm -f $(NAME)
	rm -f $(NAME)_debug
	rm -rf $(NAME)_debug.dSYM

re		: fclean all
	clear

.PHONY	: all debug clean fclean re
