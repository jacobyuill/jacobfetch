CC = gcc
CFLAGS = -Wall -Wextra

all: jacobfetch

jacobfetch: main.c
	$(CC) $(CFLAGS) -o jacobfetch main.c

clean:
	rm -f jacobfetch
