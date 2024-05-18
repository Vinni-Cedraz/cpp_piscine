CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
TARGET = megaphone
SRCS = megaphone.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean all
