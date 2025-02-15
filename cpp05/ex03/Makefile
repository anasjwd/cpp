CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror -g3
TARGET = Forms
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS = main.o Bureaucrat.o AForm.o ShrubberyCreationForm.o \
	   RobotomyRequestForm.o PresidentialPardonForm.o Intern.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
