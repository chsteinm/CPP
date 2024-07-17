NAME = Fixed
CC = c++
FLAGS = -Wall -Wextra -Werror -MMD -std=c++98 #-g3
BUILD_DIR = .build
SRCS = Fixed.cpp main.cpp
OBJS = $(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@
	@echo "\n$(NAME) is ready for use!\n"

$(BUILD_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm $(NAME)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re

.gitignore: Makefile
	@echo '.build' > .gitignore
	@echo '.vscode' >> .gitignore
	@echo $(NAME) >> .gitignore