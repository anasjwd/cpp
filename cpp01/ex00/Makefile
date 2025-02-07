CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = zombie
SRCS = newZombie.cpp randomChump.cpp main.cpp Zombie.cpp
OBJS = $(SRCS:.cpp=.o)

all = $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean clean

.PHONY: all clean fclean re
