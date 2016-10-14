NAME		=	mdos-san.filler

INCLUDES	=	includes/libft.h

LIBS		=	libft.a

TMP_SRC_C	=	main.c\
				filler_init.c\
				filler_start.c\
				check.c\
				find_by_distance.c\
				backtrack.c
SRC_C		=	$(TMP_SRC_C:%=srcs/%)
SRC_O		=	$(TMP_SRC_C:.c=.o)

all: includes libs $(NAME)

$(NAME): $(SRC_O)
	gcc -o $(NAME) $(SRC_O) $(LIBS) -I./includes

includes: $(INCLUDES)
includes/libft.h:
	cp libft/includes/libft.h includes

libs:	$(LIBS)
libft.a:
	make re -C libft
	cp libft/libft.a .
	make fclean -C libft

%.o: srcs/%.c
	gcc -c $< -I./includes

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf $(NAME) $(LIBS) $(INCLUDES)
	rm -rf filler.trace

re: fclean all
