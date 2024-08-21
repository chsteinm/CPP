NAME = Mommy
CC = c++
FLAGS = -Wall -Wextra -Werror -MMD -std=c++98 -g3
BUILD_DIR = .build
SRCS = main Bureaucrat
CPPFILES = $(addsuffix .cpp, $(SRCS))
OBJS = $(addprefix $(BUILD_DIR)/,$(CPPFILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@
	@echo "\n$(NAME) is ready for use!\n"

$(BUILD_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

%.cpp: %.hpp
	@echo '#include "$*.hpp"' > $@

%hpp:
	@UP=$(shell echo $* | tr a-z A-Z | sed 's/\.//'); \
	echo "# ifndef $${UP}_HPP" > $@; \
	echo "#define $${UP}_HPP" >> $@; \
	echo >> $@; \
	echo "#include <iostream>" >> $@; \
	echo >> $@; \
	echo "class $* {" >> $@; \
	echo "#endif" >> $@;

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re

.gitignore: Makefile
	@echo '.build' > .gitignore
	@echo '.vscode' >> .gitignore
	@echo $(NAME) >> .gitignore