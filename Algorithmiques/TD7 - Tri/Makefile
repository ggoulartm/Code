# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source files
SRCS = test.c tri.c vect.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
TARGET = TestPKG

# Default rule
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET) tempstri.dat