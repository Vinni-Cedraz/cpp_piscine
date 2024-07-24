NAME = a_few_functions
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CXX = c++
PATH_OBJS = ./objects/

SRCS = whatever
MAIN = main

OBJS = $(SRCS:%=$(PATH_OBJS)%.o)
MAIN_OBJ = $(MAIN:%=$(PATH_OBJS)%.o)

all: $(NAME)

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
