CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -ggdb
OBJS = array.o main.o

exe: $(OBJS)
	$(CC) $(OBJS) -o exe

array.o: array.c array.h
	$(CC) $(CFLAGS) -c array.c

main.o: main.c array.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o exe
