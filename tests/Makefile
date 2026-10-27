NAME = gnl_test
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
BUFF_SIZE = -D BUFFER_SIZE=10
NEUTRAL = \033[0;0m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m

SRC_DIR = ..
SRCS = $(SRC_DIR)/get_next_line.c \
	   $(SRC_DIR)/get_next_line_utils.c
TEST_MAIN = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

re: fclean all

$(NAME): $(OBJS) $(TEST_MAIN)
	@$(CC) $(CFLAGS) $^ -o $@ -I$(SRC_DIR)
	@printf "${YELLOW}Building tests ${BLUE}$@\n${NEUTRAL}"

%.o: %.c
	@$(CC) $(CFLAGS) $(BUFF_SIZE) -o $@ -c $^
	@printf "Compiling ${BLUE}$^\n${NEUTRAL}"

fclean: clean
	@rm -f $(NAME)
	@printf "${RED}Deleting archives and binaries\n${NEUTRAL}"

clean:
	@rm -f $(OBJS)
	@printf "${RED}Deleting object files\n${NEUTRAL}"

.PHONY: all fclean clean re
