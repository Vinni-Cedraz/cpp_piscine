CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
TARGET = hi_this_is_brain
SRCS = *.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS)
	@mv a.out $(TARGET)
	@make --no-print-directory clean

clean:
	@rm -f *.gch
	@rm -f $(LIBOBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
