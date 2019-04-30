CC=g++
CPPFLAGS=-I. -Wall
TARGET=pt

all: pt.cpp
	$(CC) $(CPPFLAGS) -o $(TARGET) pt.cpp

clean:
	$(RM) $(TARGET)
