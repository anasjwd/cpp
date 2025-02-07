CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = ScavTrap
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = main.o ClapTrap.o ScavTrap.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
