WARNINGS=-pedantic -Wall -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes

CC=gcc
CFLAGS=-c -std=c99 $(WARNINGS) -I.
LDFLAGS=-lm
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=gcode-gen


all: depend $(SOURCES) $(EXECUTABLE)
	chmod +x $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;

-include .depend

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -type f -name '*.o' -delete
	rm -f $(EXECUTABLE)
	rm -f ./.depend
