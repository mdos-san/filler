NAME	= mdos-san.filler

INCLUDES	=	-I./includes

TMP_SRC_C	=	main.c\
				filler_init.c
SRC_C		=	$(TMP_SRC_C:%=srcs/%)
SRC_O		=	$(TMP_SRC_C:.c=.o)

all: $(NAME)

$(NAME): $(SRC_O)
	gcc -o $(NAME) $(SRC_O) $(INCLUDES)

%.o: srcs/%.c
	gcc -c $< $(INCLUDES)

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf $(NAME)
	rm -rf filler.trace

re: fclean all
