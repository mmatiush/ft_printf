NAME :=			libftprintf.a

SRC_DIR :=		./src/
OBJ_DIR :=		./obj/
INC_DIR :=		./inc/

SRC := ft_printf.c clr_flags.c print_char.c print_invalid_specifier.c \
print_decimal.c print_unsigned.c print_percent.c print_octal.c \
print_hexadecimal.c print_padding.c print_str.c print_wchar.c \
print_wstr.c read_format_string.c ft_lutoabase.c print_binary.c

LIBFT_SRC := ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_memset.c \
ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcat.c \
ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_ischrctr.c \
ft_strwdnb.c ft_isspace.c ft_intlen.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_bzero.c

LIBFT_DIR :=	./libft/

OBJ :=			$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
LIBFT_OBJ :=	$(addprefix $(LIBFT_DIR), $(LIBFT_SRC:.c=.o))

CC_FLAGS :=		-Wall -Wextra -Werror
HEADER_FLAGS :=	-I $(INC_DIR) -I $(LIBFT_DIR)

CC :=			gcc

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(OBJ)
	ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)
	ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)

$(LIBFT_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) -I $(LIBFT_DIR)

main: $(NAME)
	$(CC) ./src/main.c $(NAME) $(HEADER_FLAGS) -o a.out

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME) a.out
	rm -rf $(OBJ_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re