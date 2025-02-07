CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = humanWithWeapon
SRCS = main.cpp Weapon.cpp HumanB.cpp HumanA.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
