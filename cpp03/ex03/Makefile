CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror -Wshadow
TARGET = DiamondTrap
SRCS = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
OBJS = main.o ClapTrap.o FragTrap.o ScavTrap.o DiamondTrap.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
