# Makefile
CC = g++
CFLAGS = -g -Wall -Wextra

# Executable name
TARGET = algo

# Object files
OBJS = main.o algorithms.o generator.o 

# Default target
default: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp algorithms.h generator.h
	$(CC) $(CFLAGS) -c main.cpp

algorithms.o: algorithms.cpp algorithms.h
	$(CC) $(CFLAGS) -c algorithms.cpp

generator.o: generator.cpp generator.h
	$(CC) $(CFLAGS) -c generator.cpp

clean:
	rm  *.o *~
