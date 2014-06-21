CC = gcc -Wall
OBJS = main.o getch.o getword.o addtree.o talloc.o treeprint.o
EXEC = keycount

$(EXEC): $(OBJS) 
	$(CC) -o $(EXEC) $(OBJS)
.c.o:
	$(CC) -c $<
clean:
	rm $(EXEC) *.o
