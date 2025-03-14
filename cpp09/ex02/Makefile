NAME = PmergeMe
CC = c++
FLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -g3
BUILD_DIR = .build
SRCS = main PmergeMe
CPPFILES = $(addsuffix .cpp, $(SRCS))
OBJS = $(addprefix $(BUILD_DIR)/,$(CPPFILES:.cpp=.o))
DEBUG = -D DEBUG=1

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
	rm -f $(NAME)

re: fclean
	@make --no-print-directory

debug: FLAGS += $(DEBUG)
debug: clean all

.PHONY: all clean fclean re debug

.gitignore: Makefile
	@echo '.build' > .gitignore
	@echo '.vscode' >> .gitignore
	@echo $(NAME) >> .gitignore