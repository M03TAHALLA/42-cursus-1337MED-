NAME = account

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp \
       tests.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Account.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re