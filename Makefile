CC = gcc
CFLAGS = -Wall -g -Werror -pedantic -ansi
SOURCES = main.c  
TARGET = ants_civ

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) -lncurses -lpanel

run:
	./$(TARGET)

clean: 
	rm -f $(TARGET)

