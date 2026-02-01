CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -Wconversion -g -std=c++98
NAME := form_up_maggots

SRCS := Bureaucrat.cpp Form.cpp main.cpp
OBJS := $(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRCS): Bureaucrat.h Form.h

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PNONY: all clean fclean re bonus rebo
