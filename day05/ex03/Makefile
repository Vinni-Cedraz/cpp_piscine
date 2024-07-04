NAME = at_least_this_beats_coffee_making
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CXX = c++
PATH_OBJS = ./objects/

SRCS = Bureaucrat Form ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm Intern
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
	rm -f I_LOVE_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all
