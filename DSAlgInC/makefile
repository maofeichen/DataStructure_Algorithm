DS: all
all: test SimpleLinkList cirDoubleLinkList

test: test.o
	gcc test.o -o bin/test
test.o: src/test.c
	gcc -c src/test.c -o test.o

SimpleLinkList: simpleLinkList.o simpleLinkListMain.o
	gcc simpleLinkList.o simpleLinkListMain.o -o bin/simpleLinkList
simpleLinkList.o: include/SimpleLinkList.h src/SimpleLinkList.c
	gcc -c src/SimpleLinkList.c -o simpleLinkList.o
simpleLinkListMain.o: include/SimpleLinkList.h src/SimpleLinkListMain.c
	gcc -c src/SimpleLinkListMain.c -o simpleLinkListMain.o

cirDoubleLinkList: cirDoubleLinkList.o cirDublLinkListMain.o
	gcc cirDoubleLinkList.o cirDublLinkListMain.o -o bin/cirDoubleLinkList
cirDoubleLinkList.o: include/cirDoubleLinkList.h src/cirDoubleLinkList.c
	gcc -c src/cirDoubleLinkList.c -o cirDoubleLinkList.o
cirDublLinkListMain.o: include/cirDoubleLinkList.h src/cirDublLinkListMain.c
	gcc -c src/cirDublLnkLstMain.c -o cirDublLinkListMain.o

clean:
	rm test.o /
	simpleLinkList.o simpleLinkListMain.o /
	cirDoubleLinkList.o cirDublLinkListMain.o
