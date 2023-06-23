CFLAGS	+= -Wall -Wextra -Wpedantic

all: lolcat

.PHONY: clean lolcat

clean:
	rm lolcat

lolcat:
	$(CC) $(CFLAGS) lolcat/lolcat.c -o lolcat/lolcat
