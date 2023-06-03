CFLAGS	+= -Wall -Wextra -Wpedantic

all:	lolcat

.PHONY: lolcat

lolcat:
	$(CC) $(CFLAGS) lolcat.c -o lolcat

