# begin of Makefile
#
CC=g++ -std=c++11
#
CFLAGS = -c -Wall -I/usr/include/mysql
#LFLAGS = -L/usr/lib/mysql -lmysqlclient
LFLAGS = 

all: lab

lab: printMeFirst.o readWine.o address.o getCity.o getPrice.o \
getRating.o getWineName.o getWineType.o getYear.o setCity.o setInfo.o \
setWineInfo.o setWineryName.o trimWords.o wine.o setAddress.o \
printInfo.o printMoreInfo.o scoreSort.o priceSort.o redWineSort.o \
whiteWineSort.o printLabels.o
	$(CC) printMeFirst.o readWine.o address.o getCity.o getPrice.o \
	getRating.o getWineName.o getWineType.o getYear.o setCity.o \
	setInfo.o setWineInfo.o setWineryName.o trimWords.o wine.o \
	setAddress.o printInfo.o printMoreInfo.o scoreSort.o priceSort.o \
	redWineSort.o whiteWineSort.o printLabels.o -o lab $(LFLAGS)

printMeFirst.o: printMeFirst.cpp
	$(CC) $(CFLAGS) printMeFirst.cpp

readWine.o: readWine.cpp
	$(CC) $(CFLAGS) readWine.cpp

address.o: address.cpp
	$(CC) $(CFLAGS) address.cpp

getCity.o: getCity.cpp
	$(CC) $(CFLAGS) getCity.cpp

getPrice.o: getPrice.cpp
	$(CC) $(CFLAGS) getPrice.cpp

getRating.o: getRating.cpp
	$(CC) $(CFLAGS) getRating.cpp

getWineName.o: getWineName.cpp
	$(CC) $(CFLAGS) getWineName.cpp

getWineType.o: getWineType.cpp
	$(CC) $(CFLAGS) getWineType.cpp

getYear.o: getYear.cpp
	$(CC) $(CFLAGS) getYear.cpp

setCity.o: setCity.cpp
	$(CC) $(CFLAGS) setCity.cpp

setInfo.o: setInfo.cpp
	$(CC) $(CFLAGS) setInfo.cpp

setWineInfo.o: setWineInfo.cpp
	$(CC) $(CFLAGS) setWineInfo.cpp

setWineryName.o: setWineryName.cpp
	$(CC) $(CFLAGS) setWineryName.cpp

trimWords.o: trimWords.cpp
	$(CC) $(CFLAGS) trimWords.cpp

wine.o: wine.cpp
	$(CC) $(CFLAGS) wine.cpp

setAddress.o: setAddress.cpp
	$(CC) $(CFLAGS) setAddress.cpp

printInfo.o: printInfo.cpp
	$(CC) $(CFLAGS) printInfo.cpp

printMoreInfo.o: printMoreInfo.cpp
	$(CC) $(CFLAGS) printMoreInfo.cpp

scoreSort.o: scoreSort.cpp
	$(CC) $(CFLAGS) scoreSort.cpp

priceSort.o: priceSort.cpp
	$(CC) $(CFLAGS) priceSort.cpp

redWineSort.o: redWineSort.cpp
	$(CC) $(CFLAGS) redWineSort.cpp

whiteWineSort.o: whiteWineSort.cpp
	$(CC) $(CFLAGS) whiteWineSort.cpp

printLabels.o: printLabels.cpp
	$(CC) $(CFLAGS) printLabels.cpp
clean:
	rm *.o lab

run:
	./lab

#end of makefile
