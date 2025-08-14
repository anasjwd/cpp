CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = btc
SRCS = main.cpp BitcoinExchange.cpp
OBJS = main.o BitcoinExchange.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
