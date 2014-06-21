CC = gcc -Wall
OBJS = main.o alloc.o
EXEC = test

$(EXEC): $(OBJS) 
	$(CC) -o $(EXEC) $(OBJS)
.c.o:
	$(CC) -c $<
clean:
	rm $(EXEC) *.o
