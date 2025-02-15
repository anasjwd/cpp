CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = Bureaucrat
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = main.o Bureaucrat.o Form.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
