NAME = gnl_test.out
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
BUFF_SIZE = 1
BUFF_FLAG = -D BUFFER_SIZE=$(BUFF_SIZE)
NEUTRAL = \033[0;0m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
GREEN = \e[0;32m

SRC_DIR = ..
SRCS = $(SRC_DIR)/get_next_line.c \
	   $(SRC_DIR)/get_next_line_utils.c
TEST_MAIN = main.c
OBJS = $(SRCS:.c=.o)

EMPTY = empty.txt
NL = nl.txt
ONE = one.txt
LIPSUM = lipsum.txt
TEST_FILES = $(EMPTY) \
			 $(NL) \
			 $(ONE) \
			 $(LIPSUM)
LOG_FILE = tests.log

all: $(NAME)

re: fclean all

$(NAME): $(OBJS) $(TEST_MAIN)
	@$(CC) $(CFLAGS) $^ -o $@ -I$(SRC_DIR)
	@printf "${YELLOW}Building tests ${BLUE}$@\n${NEUTRAL}"

%.o: %.c
	@$(CC) $(CFLAGS) $(BUFF_FLAG) -o $@ -c $^
	@printf "Compiling ${BLUE}$^\n${NEUTRAL}"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LOG_FILE)
	@printf "${RED}Deleting logs and binaries\n${NEUTRAL}"

clean:
	@rm -f $(OBJS)
	@printf "${RED}Deleting object files\n${NEUTRAL}"

tests: $(TEST_FILES) $(NAME)
	@touch $(LOG_FILE)
	@printf "${GREEN}Testing empty file...\n"
	@printf "Testing empty file...\n<<" 1>$(LOG_FILE)
	@./$(NAME) $(EMPTY) 1>>$(LOG_FILE)
	@printf "${GREEN}Testing new line file...\n"
	@printf ">>\nTesting new line file...\n<<" 1>>$(LOG_FILE)
	@./$(NAME) $(NL) 1>>$(LOG_FILE)
	@printf "${GREEN}Testing one byte file...\n"
	@printf ">>\nTesting one byte file...\n<<" 1>>$(LOG_FILE)
	@./$(NAME) $(ONE) 1>>$(LOG_FILE)
	@printf "${GREEN}Testing lipsum file...\n${NEUTRAL}"
	@printf ">>\nTesting lipsum file...\n<<" 1>>$(LOG_FILE)
	@./$(NAME) $(LIPSUM) 1>>$(LOG_FILE)
	@printf ">>" 1>>$(LOG_FILE)
	@printf "Test results available in ${BLUE}${LOG_FILE}${NEUTRAL}"

.PHONY: all fclean clean re tests
