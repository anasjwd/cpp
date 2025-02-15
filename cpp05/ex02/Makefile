CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
TARGET = Forms
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = main.o Bureaucrat.o AForm.o ShrubberyCreationForm.o \
	   RobotomyRequestForm.o PresidentialPardonForm.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
