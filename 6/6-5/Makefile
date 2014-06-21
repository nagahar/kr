CC = gcc -Wall
OBJS = main.o getch.o hash.o
EXEC = test

$(EXEC): $(OBJS) 
	$(CC) -o $(EXEC) $(OBJS)
.c.o:
	$(CC) -c $<
clean:
	rm $(EXEC) *.o
