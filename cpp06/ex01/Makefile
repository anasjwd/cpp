CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = Serialize
SRCS = main.cpp Serializer.cpp Data.cpp
OBJS = main.o Serializer.o Data.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
