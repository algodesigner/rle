clean:
	rm -rf rle unrle

build:
	gcc -std=c99 -o rle rle.c
	gcc -std=c99 -o unrle unrle.c

all: clean build
