CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -Wconversion -g -std=c++98
NAME := no_you_need_form_28b_not_28c

SRCS := Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp main.cpp
OBJS := $(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PNONY: all clean fclean re bonus rebo
