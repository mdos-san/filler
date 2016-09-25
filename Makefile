NAME	= mdos-san.filler

TMP_SRC_C	=	main.c
SRC_C		=	$(TMP_SRC_C:%=srcs/%)
SRC_O		=	$(TMP_SRC_C:.c=.o)

all: $(NAME)

$(NAME): $(SRC_O)
	gcc -o $(NAME) $(SRC_O)

%.o: srcs/%.c
	gcc -c $<

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf $(NAME)

re: fclean all
