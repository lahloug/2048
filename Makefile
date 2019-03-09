.PHONY: clean all ftest

EXEC=main
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: clean $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) $^ -o $@

%.o:%.c
	@$(CC) -c $^

clean:
	@rm -f *.o
	@rm -f $(EXEC)

ftest:
	@make all
	@./$(EXEC)
	@make clean
