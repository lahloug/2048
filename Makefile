.PHONY: clean all ftest local_ci_test local_test test

EXEC=main
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: clean $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) $^ -o $@
	@./$@

%.o:%.c
	@$(CC) -c $^

clean:
	@rm -f *.o game-test.c
	@rm -f $(EXEC)
	@rm -f test_script

ftest:
	@make all
	@./$(EXEC)
	@make clean
test: clean
	checkmk game-test.check > game-test.c
	gcc game.c game-test.c -o test_script -lcheck -lrt -lm -lpthread -lsubunit
	./test_script

local_test: clean
	checkmk game-test.check > game-test.c
	gcc game.c game-test.c -o test_script -lcheck
	./test_script

local_ci_test:
	circleci local execute --job build
