CC = gcc

CFLAGS = -Wall -g -Iinclude -pthread

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

TARGET = rf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
