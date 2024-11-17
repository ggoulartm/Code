# Makefile for SharedSuffixes project

CC = gcc
CFLAGS = -Wall -g
TARGET = testTree
SOURCES = testSharedSuffixes.c dotGraph.c PatriciaTreeSharedSuffixes.c
DOT = dot
DOTFLAGS = -Tpng
DOTFILE = tree.dot
OUTPUT = tree.png

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

plot: $(DOTFILE)
	$(DOT) $(DOTFLAGS) $(DOTFILE) -o $(OUTPUT)

clean:
	rm -f $(TARGET) $(OUTPUT)

.PHONY: all plot clean