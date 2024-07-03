CC=gcc
CFLAGS=-g
override CROSS_COMPILE=aarch64-none-linux-gnu-

default:writer
writer:
	aarch64-none-linux-gnu-gcc -o writer.out writer.c

clean:
	rm -f writer *.o

#ifeq ( $(CROSS_COMPILE), aarch64-none-linux-gnu-)
#	aarch64-none-linux-gnu-gcc -o writer.out writer.c
#endif
#ifndef $(CROSS_COMPILE)
#	$(CC) $(CFLAGS) -o gcc_writer writer.c
#endif

