CC = gcc

CFLAGS = -Wall -g

SRCS = src/main.c src/utils.c

OBJS = $(SRCS:.c=.o)

TARGET = dist

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
