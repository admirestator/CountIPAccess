######################################################################
## Filename:      Makefile
## Version:       
## Author:        吴旭 <admirestator@gmail.com>
## Created at:    Fri Mar  9 13:04:10 2012
## Description:   makefile for ip finder.
######################################################################

CXX=g++
CXXFLAGS=-Wall -O2

TARGET=count
SRC=main.cpp ip.cpp loganalysis.cpp
OBJ=main.o ip.o loganalysis.o

$(TARGET):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

count.o:main.cpp
	$(CXX) -c main.cpp

ip.o:ip.cpp
	$(CXX) -c ip.cpp

loganalysis.o:loganalysis.cpp
	$(CXX) -c loganalysis.cpp

clean:
	rm -rf $(TARGET) $(OBJ)
