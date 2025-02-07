CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = ClapTrap
SRCS = main.cpp ClapTrap.cpp
OBJS = main.o ClapTrap.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
