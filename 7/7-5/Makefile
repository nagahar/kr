CC = gcc -Wall
OBJS = main.o getline.o
EXEC = calc

$(EXEC): $(OBJS) 
	$(CC) -lm -o $(EXEC) $(OBJS)
.c.o:
	$(CC) -c $<
clean:
	rm $(EXEC) *.o
