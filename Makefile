CC = gcc

CFLAGS = -Wall -g -Iinclude

SRCS = src/main.c src/utils.c src/file.c

OBJS = $(SRCS:.c=.o)

TARGET = remof

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
