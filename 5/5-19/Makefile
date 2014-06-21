CC		= gcc -Wall
OBJS	= main.o getch.o
EXEC	= undcl

$(EXEC): $(OBJS) 
	$(CC) -o $(EXEC) $(OBJS)

.c.o:
	$(CC) -c $<

main.o: main.h
dcl.o: main.h

clean:
	rm $(EXEC) *.o
