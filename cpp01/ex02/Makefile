CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = PtrVsRef
SRCS = main.cpp
OBJS = main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
