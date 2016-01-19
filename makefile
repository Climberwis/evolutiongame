CC=gcc
CFLAGS= -c -Wall -ansi -O
GTKFLAGS= `pkg-config gtk+-2.0 --cflags` `pkg-config gtk+-2.0 --libs`

all: lGoEv

debug: main.c life.c life.h
	$(CC) -g main.c life.c -o lGoEvdeb $(GTKFLAGS)

lGoEv: main.o life.o
	$(CC) main.o life.o -o lGoEv $(GTKFLAGS)

main.o: main.c life.h
	$(CC) $(CFLAGS) main.c $(GTKFLAGS)

life.o: life.c life.h
	$(CC) $(CFLAGS) life.c $(GTKFLAGS)

clean:
	rm *o lGoEv

clall:
	rm -rf *.o *.c *.h lGoEv lGimg/

