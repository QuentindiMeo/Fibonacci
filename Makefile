##
## PERSONAL PROJECT, 2019
## fibonacci
## File description:
## Makefile
##

SRC	=	src/help.c				\
		src/turbo.c				\
		src/detectors.c			\
		src/writing.c			\
		src/reading.c			\
		src/setup.c				\
		src/main_fibonacci.c

OBJ	=	$(SRC:.c=.o)

HEADER_PATH     =       include/

CC	=	@gcc

LIB     =       include/libmy.a

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic

NAME	=	fibonacci

OUTPUTTXT	=	calculations_fib.txt

.PHONY: clean fclean re fibonacci

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'
	@rm -rf $(OUTPUTTXT)
	@echo Cleaned \'$(OUTPUTTXT)\'

re: fclean all
