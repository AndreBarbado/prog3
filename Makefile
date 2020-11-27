CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra -c

all: prog
	
prog: main.o vendas.o data.o ESTOQUE.o
	$(CC) main.o vendas.o data.o ESTOQUE.o -o prog

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
ESTOQUE.o: ESTOQUE.cpp
	$(CC) $(CFLAGS) ESTOQUE.cpp

vendas.o: vendas.cpp
	$(CC) $(CFLAGS) vendas.cpp

data.o: data.cpp
	$(CC) $(CFLAGS) data.cpp



exe:
	./prog

clean:
	rm -rf *o prog