NAME = libftprintf.a

TEST = ft_printf

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_L = srcs/

INCLUDES = -I includes/ -I libft/

LIST = 		ft_printf.c \
			ft_printString.c \
			ft_analysisFlags.c\
			ft_printValue.c \
			ft_printChar.c \
			ft_printPrecent.c \
			ft_printInteger.c \
			ft_printUnsingedInt.c \
			ft_printPointer.c \
			ft_printHexadecimal.c


OBJS =$(SRCS:.c=.o)

SRCS = $(addprefix $(DIR_L), $(LIST))

all: $(NAME)

$(NAME): my_lib $(OBJS)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

my_lib: 
	make -C $(LIBFT)

%.o: %.c includes/ft_printf.h
	gcc -g $(FLAGS) $(INCLUDES) -c $< -o $@

test: $(NAME)
	gcc -g $(INCLUDES) srcs/main.c -lftprintf -L. -o $(TEST)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

tclean:
	rm $(TEST)

re: fclean all

.PHONY: fclean re norme all clean
