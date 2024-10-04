NAME = canon_in_orthodox

CFLAGS = -Wall -Wextra -Werror -std=c++11

SOURCES =	main.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	c++ $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o:%.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
