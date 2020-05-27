#
#
CC=g++ -std=c++11
#
CFLAGS = -c -Wall -I/usr/include/mysql 
LFLAGS = -L/usr/lib/mysql -lmysqlclient



all: lab

lab: printMeFirst.o main.o menu.o scoreComparison.o priceComparison.o vintageComparison.o \
dbconnect.o wine.o setName.o setVintage.o setRating.o \
setPrice.o setType.o printInfo.o setWineInfo.o
	$(CC) printMeFirst.o main.o menu.o scoreComparison.o priceComparison.o vintageComparison.o \
	dbconnect.o wine.o setName.o setVintage.o setRating.o \
	setPrice.o setType.o printInfo.o setWineInfo.o -o lab $(LFLAGS)

printMeFirst.o: printMeFirst.cpp lab.h
	$(CC) $(CFLAGS) printMeFirst.cpp

dbconnect.o: dbconnect.cpp dbconnect.h
	$(CC) $(CFLAGS) dbconnect.cpp

wine.o: wine.cpp lab.h
	$(CC) $(CFLAGS) wine.cpp

setName.o: setName.cpp lab.h
	$(CC) $(CFLAGS) setName.cpp

setVintage.o: setVintage.cpp lab.h
	$(CC) $(CFLAGS) setVintage.cpp

setRating.o: setRating.cpp lab.h
	$(CC) $(CFLAGS) setRating.cpp

setPrice.o: setPrice.cpp lab.h
	$(CC) $(CFLAGS) setPrice.cpp

setType.o: setType.cpp lab.h
	$(CC) $(CFLAGS) setType.cpp

printInfo.o: printInfo.cpp lab.h
	$(CC) $(CFLAGS) printInfo.cpp

setWineInfo.o: setWineInfo.cpp lab.h
	$(CC) $(CFLAGS) setWineInfo.cpp

menu.o: menu.cpp lab.h
	$(CC) $(CFLAGS) menu.cpp

scoreComparison.o: scoreComparison.cpp lab.h
	$(CC) $(CFLAGS) scoreComparison.cpp

priceComparison.o: priceComparison.cpp lab.h
	$(CC) $(CFLAGS) priceComparison.cpp

vintageComparison.o: vintageComparison.cpp lab.h dbconnect.h
	$(CC) $(CFLAGS) vintageComparison.cpp

main.o: main.cpp lab.h
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o lab

run:
	./lab "select name, vintage, score, price, type from wineInfo where price > 100"


#end of Makefile
