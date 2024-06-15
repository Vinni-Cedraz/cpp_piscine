CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
TARGET = repetitive_work
SRCS = *.cpp

all: $(TARGET)
	@echo "name of the executable is: " $(TARGET)

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
