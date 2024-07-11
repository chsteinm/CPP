NAME = HI_BRAIN
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
BUILD_DIR = .build
SRCS = main.cpp
OBJS = $(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@
	@echo "\n$(NAME) is ready for use!\n"

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