NAME = phonebook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
BUILD_DIR = .build
SRC = phonebook.cpp contact.cpp main.cpp
OBJ = $(addprefix $(BUILD_DIR)/,$(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@
	@echo "\n$(NAME) is ready for use!\n"

$(BUILD_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

include $(OBJS:.o=.d)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm $(NAME)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re bonus