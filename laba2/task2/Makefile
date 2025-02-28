CXX = gcc
TARGET = task2
SRC = task2.c
CXXFLAGS = -fopenmp
BIB = -lm

all: $(TARGET)

$(TARGET): $(SRC) Makefile
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(BIB)

clean:
	rm $(TARGET)