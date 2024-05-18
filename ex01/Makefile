CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
TARGET = phonebook
SRCS = *.cpp *.hpp

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

## TEST RULES
LIBSRCS = Contact.cpp PhoneBook.cpp
LIBOBJS = $(LIBSRCS:.cpp=.o)
as_lib: $(LIBOBJS)
	@ar rcs tests/$(TARGET).a $(LIBOBJS)
	@make --no-print-directory clean
