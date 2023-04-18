# Target library
CC=g++
TARGET=most_often.x
CFLAGS=-Wall
SRC=most_often.cpp

all:
	$(CC) $(CFLAGS)  $(SRC) -o $(TARGET)

clean: 
	rm $(TARGET)
