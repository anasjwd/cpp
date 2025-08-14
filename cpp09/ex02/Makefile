CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror 
TARGET = PmergeMe
SRCS = main.cpp PmergeMe.cpp
OBJS = main.o PmergeMe.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
