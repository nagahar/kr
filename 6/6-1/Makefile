CC = gcc -Wall
OBJS = main.o getch.c 
EXEC = keycount
INC	=  main.h

$(EXEC): $(OBJS) 
	$(CC) -o $(EXEC) -include $(INC) $(OBJS)
.c.o:
	$(CC) -include $(INC) -c $<
clean:
	rm $(EXEC) *.o
