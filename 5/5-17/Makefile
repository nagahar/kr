CC = gcc -Wall
OBJS = main.o alloc.o getline.o numcmp.o qsort.o strcmpf.o dircmp.o atoi.c getstart.o 
EXEC = sort
INC	=  main.h

$(EXEC): $(OBJS) 
	$(CC) -o $(EXEC) -include $(INC) $(OBJS)
.c.o:
	$(CC) -include $(INC) -c $<
clean:
	rm $(EXEC) *.o
