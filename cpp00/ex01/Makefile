CXX=c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = phonebook
OBJS = Contact.o main.o PhoneBook.o
SRCS = Contact.cpp main.cpp PhoneBook.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
