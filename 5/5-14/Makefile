CC = gcc -Wall
OBJS = main.o alloc.o getline.o numcmp.o qsort.o readline.o
EXEC = sort

$(EXEC): $(OBJS) 
	$(CC) -o $(EXEC) $(OBJS)
.c.o:
	$(CC) -c $<
clean:
	rm $(EXEC) *.o
