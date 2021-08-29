CC=clang
CFLAGS=-g
LDFLAGS=

all: bin/pis

bin/pis: *.c
	$(CC) $(CFLAGS)  -o bin/pis *.c $(LDFLAGS)

clean:
	rm -rf bin/*