CC		= gcc -Wall
OBJS	= main.o dcl.o getch.o
EXEC	= dcl

$(EXEC): $(OBJS) 
	$(CC) -o $(EXEC) $(OBJS)

.c.o:
	$(CC) -c $<

main.o: main.h
dcl.o: main.h

clean:
	rm $(EXEC) *.o
