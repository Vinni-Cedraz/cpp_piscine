NAME = convert
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CXX = c++
PATH_OBJS = ./objects/

SRCS = ScalarConverter
MAIN = main

CYAN = \033[0;36m
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

OBJS = $(SRCS:%=$(PATH_OBJS)%.o)
MAIN_OBJ = $(MAIN:%=$(PATH_OBJS)%.o)

all: $(NAME)

define run_test
	@echo "$(CYAN)./$(NAME)$(RESET) $(1)"
	@valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full -q ./$(NAME) $(1)
endef

tests:
	$(call run_test,0)
	$(call run_test,nan)
	$(call run_test,+inf)
	$(call run_test,-inf)
	$(call run_test,-inff)
	$(call run_test,+inff)
	$(call run_test,12)
	$(call run_test,-12)
	$(call run_test,32)
	$(call run_test,120)
	$(call run_test,-120)
	$(call run_test,97)
	$(call run_test,98)
	$(call run_test,99)
	$(call run_test,100)
	$(call run_test,101)
	$(call run_test,102)
	$(call run_test,42)
	$(call run_test,-42)
	$(call run_test,42.0)
	$(call run_test,42.123)
	$(call run_test,-42.123)
	$(call run_test,42.123198231928312983)
	$(call run_test,-42.123198231928312983)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CXX) $(FLAGS) $^ -o $(NAME)

$(PATH_OBJS)%.o: %.cpp %.hpp
	@mkdir -p $(PATH_OBJS)
	$(CXX) $(FLAGS) -c $< -o $@

$(MAIN_OBJ): $(MAIN).cpp
	@mkdir -p $(PATH_OBJS)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(PATH_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
