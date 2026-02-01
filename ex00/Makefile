CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -Wconversion -g -std=c++98
NAME := mommy_when_I_grow_up_I_want_to_be_a_bureaucrat

SRCS := Bureaucrat.cpp main.cpp
OBJS := $(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRCS): Bureaucrat.h

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PNONY: all clean fclean re bonus rebo
