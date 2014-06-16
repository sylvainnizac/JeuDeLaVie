CC=gcc
CFLAGS=-W -Wall -Werror
LDFLAGS=-L. -lctoolbox -lm
EXEC=jeu_de_la_vie
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)
	export LD_LIBRARY_PATH=$(PWD)

jeu_de_la_vie: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrpropre rebuild

clean:
	rm -rf *.o *~

mrpropre: clean
	rm -rf $(EXEC)

rebuild: mrpropre all
