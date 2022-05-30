CC=gcc
all: bin bin/ifsfs

bin:
	mkdir bin

bin/ifsfs:
	$(CC) src/*.cpp -lstdc++ -o bin/ifsfs

clean:
	rm -r bin