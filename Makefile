NAME :=			a.out

SRC_DIR :=		./src/
OBJ_DIR :=		./obj/
INC_DIR :=		./inc/

SRC =			ft_printf.c main.c clr_flags.c print_char.c print_padding.c

OBJ :=			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT :=		libft.a
LIBFT_DIR :=	./libft/
LIBFT_FLAGS :=	-L $(LIBFT_DIR) -lft

CC_FLAGS :=		-Wall -Wextra -Werror
HEADER_FLAGS :=	-I $(INC_DIR) -I $(LIBFT_DIR)

CC :=			gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(INC_DIR)ft_printf.h
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re