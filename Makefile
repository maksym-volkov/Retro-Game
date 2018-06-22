NAME     := test

SRCS     := main.cpp Test.cpp
OBJS     := $(SRCS:.cpp=.o)

G     	 := g++
FLAGS 	 := -Wall -Werror -Wextra
LNFLAGS  := -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	@$(G) $(OBJS) $(LNFLAGS) -o $@

%.o: %.cpp
	$(G) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re