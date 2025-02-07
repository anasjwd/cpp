CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = Animals
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = main.o Animal.o Dog.o Cat.o WrongCat.o WrongAnimal.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
