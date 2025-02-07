CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = BSP
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = main.o Fixed.o Point.o bsp.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
