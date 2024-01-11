NAME 	= so_long

FTPRINTF = ft_printf/

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror -g

SRCS 	=	main.c check/convert_map.c getnextline/get_next_line.c getnextline/get_next_line_utils.c \
		check/ft_check_error.c check/ft_check_map.c textures/ft_load_img.c textures/ft_movement.c \
		textures/ft_reload.c textures/ft_endgame.c utils/ft_strdup.c utils/itoa.c \
		time/frame.c time/c.c \

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@ make -C $(FTPRINTF)
	@$(CC) -lmlx -framework OpenGL -framework AppKit ft_printf/libftprintf.a  $^ -o $@
	@echo "\[\033[4;35m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "                                \033[44mFatto Da: DIO"

all: $(NAME)


%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@make clean -C $(FTPRINTF)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(FTPRINTF)
	@rm -f $(NAME)

re: fclean all