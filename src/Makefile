CFLAGS = -Wall -Wextra `pkg-config fuse3 --cflags`
LIBS = `pkg-config fuse3 --libs`

all: simple_fs

simple_fs: simple_fs.o
	$(CC) -o $@ $^ $(LIBS)

simple_fs.o: simple_fs.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f simple_fs simple_fs.o
