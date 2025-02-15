CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = Convert
SRCS = main.cpp ScalarConverter.cpp
OBJS = main.o ScalarConverter.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
