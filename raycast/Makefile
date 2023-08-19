NAME        := raycast
CC          := cc
CFLAGS      := -Wextra -Wall -Werror
CFLAGS      += -Wunreachable-code -Ofast
CFLAGS      += -g3 -fsanitize=address

INCLUDE_DIR := .
HEADERS		:= -I $(INCLUDE_DIR)

SRC         := \
			raycast.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(HEADERS) $(SRC) -o $(NAME) && \
	echo "$(BLUE)Compilation of $(CYAN)>>$(NAME)<<$(RESET)$(BLUE) successful!$(RESET)"

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
