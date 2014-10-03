# makefile
# @author mchen
# makefile for Algorithm C version

test_heap : heap.o src/queue/test_heap.c common.o
	cc -o bin/test_heap heap.o src/queue/test_heap.c -lm \
		common.o

heap.o : src/queue/heap.c include/queue/heap.h 
	cc -c src/queue/heap.c 

common.o : src/common.c
	cc -c src/common.c

clean :
	rm bin/test_heap src/queue/heap.o
