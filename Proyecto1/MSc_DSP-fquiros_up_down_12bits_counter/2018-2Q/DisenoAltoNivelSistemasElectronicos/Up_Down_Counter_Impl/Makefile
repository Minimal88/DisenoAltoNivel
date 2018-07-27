CC = g++
FILE = up_down_12bits_counter_tb.cpp
EXECUTABLE = up_down_12bits_counter

CFLAGS = -g -Wall

.PHONY: clean

build:
	g++ -I. -I${SYSTEMC_HOME}/include -L. -L${SYSTEMC_HOME}/lib-linux64 -Wl,-rpath=${SYSTEMC_HOME}/lib-linux64 -o ${EXECUTABLE} ${FILE} -lsystemc -lm


clean:
	rm -rf $(EXECUTABLE)
