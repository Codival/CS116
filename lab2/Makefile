# begin of Makefile
#
CC=g++
#
CFLAGS = -c -Wall -I/usr/include/mysql
#LFLAGS = -L/usr/lib/mysql -lmysqlclient
LFLAGS = 

all: main

main: main.o bank.o account.o printMeFirst.o
	$(CC) main.o bank.o account.o  printMeFirst.o -o lab $(LFLAGS)

bank.o: bank.cpp bank.h
	$(CC) $(CFLAGS) bank.cpp

account.o: account.cpp account.h
	$(CC) $(CFLAGS) account.cpp

printMeFirst.o: printMeFirst.cpp 
	$(CC) $(CFLAGS) printMeFirst.cpp

clean:
	rm *.o lab

run:
	./lab

#end of Makefile
