# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/28 11:49:30 by mtahalla          #+#    #+#              #
#    Updated: 2025/05/28 11:49:34 by mtahalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       Contact.cpp \
       PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Contact.hpp \
          PhoneBook.hpp

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