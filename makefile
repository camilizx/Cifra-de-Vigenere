op=-o
file=bin

all: build run

run:
	./trabalho.exe

build:
	g++ main.cpp src/utilities.cpp src/attack.cpp src/enc-dec.cpp src/freqanalysis.cpp src/keylength.cpp -o trabalho

clean:
	del trabalho.exe
