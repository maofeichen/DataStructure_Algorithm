# ###################################################################### 
# makefile
# @author mchen
# makefile for Algorithm C version
# ###################################################################### 

CC 		= g++
CF 		= -Wall -g -std=c++11
LF 		= -g

DIR_OBJS	= ./build/
SRC 	= ./src/
INC 	= -Iinclude

all : test

test : test_main.o insertion.o
	$(CC) $(LF) -o test $(DIR_OBJS)test_main.o $(DIR_OBJS)insertion.o 


test_main.o : $(SRC)test_main.cpp
	$(CC) $(INC) $(CF) -c $(SRC)test_main.cpp -o $(DIR_OBJS)test_main.o 

insertion.o : $(SRC)insertion.cpp
	$(CC) $(INC) $(CF) -c $(SRC)insertion.cpp -o $(DIR_OBJS)insertion.o 

# test_heap : heap.o src/queue/test_heap.c common.o
# 	cc -o bin/test_heap heap.o src/queue/test_heap.c -lm \
		common.o

# test_ll_singly : ll_singly.o src/list/test_ll_singly.c
# 	cc -o bin/test_ll_singly obj/ll_singly.o src/list/test_ll_singly.c -ggdb

# heap.o : src/queue/heap.c include/queue/heap.h 
# 	cc -c src/queue/heap.c 

# ll_singly.o : src/list/ll_singly.c include/list/ll_singly.h
# 	cc -c src/list/ll_singly.c -o obj/ll_singly.o -ggdb

#common.o : src/common.c
#	cc -c src/common.c

clean :
	rm -f test $(DIR_OBJS)*.o 
#	rm bin/test_heap src/queue/heap.o
