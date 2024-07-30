NAME = easyfind
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CXX = c++
PATH_OBJS = ./objects/

SRCS = easyfind
MAIN = main

OBJS = $(SRCS:%=$(PATH_OBJS)%.o)
MAIN_OBJ = $(MAIN:%=$(PATH_OBJS)%.o)

all: $(NAME)

run:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

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
