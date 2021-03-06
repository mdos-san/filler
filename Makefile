NAME		=	mdos-san.filler
FLAG		=	-Werror -Wextra -Wall -Wpedantic

INCLUDES	=	includes/libft.h

LIBS		=	libft.a

TMP_SRC_C	=	main.c\
				filler_init.c\
				filler_start.c\
				check.c\
				territory_control.c\
				explore.c\
				get_new_piece.c\
				ctl.c\
				lst_filler.c
SRC_C		=	$(TMP_SRC_C:%=srcs/%)
SRC_O		=	$(TMP_SRC_C:.c=.o)

all: includes libs $(NAME)

$(NAME): $(SRC_O)
	@echo "Linking $(NAME):\c"
	@gcc $(FLAG) -o $(NAME) $(SRC_O) $(LIBS) -I./includes
	@echo "[ok]"

includes: $(INCLUDES)
includes/libft.h:
	cp libft/includes/libft.h includes

libs:	$(LIBS)
libft.a:
	make re -C libft
	cp libft/libft.a .
	make fclean -C libft

%.o: srcs/%.c
	@echo "Compiling $<:\c"
	@gcc $(FLAG) -c $< -I./includes
	@echo "[ok]"

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf $(NAME) $(LIBS) $(INCLUDES)
	rm -rf filler.trace
	rm -rf log

re: fclean all
