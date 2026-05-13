TARGET= writer

CC = $(CROSS_COMPILE)gcc
.PHONY: clean

writer : writer.o
	$(CC) -o writer writer.o
writer.o: writer.c
	$(CC) -c writer.c -o writer.o
clean:
	rm -rf *.o writer
