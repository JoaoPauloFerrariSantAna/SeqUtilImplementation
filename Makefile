CFLAGS := -Wall -Wextra -Wpedantic -Werror -ansi
CC := gcc

all:
	$(CC) $(CFLAGS) main.c -o myseq
