CC = g++
FILE = aluModule.cpp
EXECUTABLE = alu

CFLAGS = -g -Wall

.PHONY: clean

build:
	$(CC) -I. -I${SYSTEMC_HOME}/include -L. -L${SYSTEMC_HOME}/lib-linux64 -Wl,-rpath=${SYSTEMC_HOME}/lib-linux64 -std=c++11 -o $(EXECUTABLE) $(FILE) -lsystemc -lm

clean:
	rm -rf $(EXECUTABLE)
