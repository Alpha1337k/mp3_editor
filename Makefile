NAME=mp3_editor

CC=clang++
FLAGS=-Wall -Werror -Wextra -std=c++2a
DEBUG_FLAGS=-g -fsanitize=address
SRC=src/*.cpp
LIBS=-I inc/
OBJ=
RM =rm -rf

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(LIBS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)

debug: fclean
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(LIBS) $(SRC) -o $(NAME)
