CC = g++
CFLAGS = -Wall -g -fstack-protector-strong -O2 -c

CFLAGS_HARDEN= -O3 -fstack-protector-all -D_FORTIFY_SOURCE=2 -fstack-protector-strong -fcf-protection -c
all: src/main.cpp src/main.h lib/serialib.h lib/serial.cpp
	$(CC) $(CFLAGS) src/main.cpp -o build/main.o
	$(CC) $(CFLAGS) lib/serial.cpp -o build/serial.o

link: build/main.o build/serial.o
	$(CC) -o bin/app.out build/serial.o build/main.o

clean:
	rm -rf build/*.o

harden: src/main.cpp src/main.h lib/serialib.h lib/serial.cpp 
	$(info Dont harden during testing. Also may reduce perfomance)
	$(CC) $(CFLAGS_HARDEN) src/main.cpp -o build/main.o
	$(CC) $(CFLAGS_HARDEN) lib/serial.cpp -o build/serial.o

