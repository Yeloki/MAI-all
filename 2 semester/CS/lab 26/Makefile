CC = gcc
CFLAGS = -std=c99 -pedantic -Wall
LDFLAGS = 
EXECUTABLE = prog
SRC = main.c sort.c list.c iter.c
OBJ = $(SRC:.c=.o)

$(EXECUTABLE): $(OBJ) 
	$(CC) $(LDFLAGS) $(OBJ) -o $(EXECUTABLE)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

sort.o: sort.c list.h iter.h

list.o: list.c iter.h

iter.o: iter.c list.h iter.h

main.o: main.c sort.h list.h

clean:
	rm *.o $(EXECUTABLE)
