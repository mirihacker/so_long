NAME	:= so_long
CC := gcc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42
FT_PRINTF_LIBDIR := ./ft_printf
LIBFT_LIBDIR := ./libft
LIBFLAG = -lftprintf -lft -L$(FT_PRINTF_LIBDIR) -L$(LIBMLX) -L$(LIBFT_LIBDIR)

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= check_map.c check_path.c error_handler.c graphic_handler.c \
			key_handler.c move_handler.c so_long.c utils.c
OBJS	:= ${SRCS:.c=.o}

GREEN :='\033[0;32m'
NC := '\033[0m'

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@make -C ./ft_printf
	@make -C ./libft
	@$(CC) $(OBJS) $(LIBS) $(LIBFLAG) $(HEADERS) -o $(NAME)
	@echo "	███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ "
	@echo " 	██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ "
	@echo " 	███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗ "
	@echo " 	╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║ "
	@echo " 	███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝ "
	@echo " 	╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ "
	@echo ${GREEN}"You can start testing:"
	@echo "./so_long maps/valid/<map name>"${NC}
	
clean:
	@make -C ./ft_printf clean
	@make -C ./libft clean
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build clean

fclean: clean
	@make -C ./ft_printf fclean
	@make -C ./libft fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re libmlx