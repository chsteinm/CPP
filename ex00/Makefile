NAME = megaphone
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
BUILD_DIR = .build
SRC = megaphone.cpp
OBJ = $(addprefix $(BUILD_DIR)/,$(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@
	@echo "\nmegaphone is ready for use!\n"

$(BUILD_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm $(NAME)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re bonus