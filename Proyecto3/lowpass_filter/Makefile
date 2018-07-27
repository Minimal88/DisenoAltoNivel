CC = g++
FILE = main.cpp
EXECUTABLE = main

CFLAGS = -g -Wall

TARGET_ARCH = linux64


INCDIR = -I. -I.. -I${SYSTEMC_HOME}include -I${SYSTEMC_AMS_HOME}include 
LIBDIR = -L. -L.. -L$(SYSTEMC_HOME)/lib-$(TARGET_ARCH) -lsystemc -L$(SYSTEMC_AMS_HOME)/lib-$(TARGET_ARCH) -lsystemc-ams

LIBS   = -lpthread -lm

.PHONY: clean

build:
	rm -rf $(EXECUTABLE)
	$(CC) $(INCDIR) $(LIBDIR) -Wl,-rpath=${SYSTEMC_HOME}lib-linux64/ -Wl,-rpath=${SYSTEMC_AMS_HOME}lib-linux64/ -std=c++11 -o $(EXECUTABLE) $(FILE) 
	chmod +x $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE)
