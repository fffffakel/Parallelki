CXX = gcc
TARGET = task1
SRC = task1.c
CXXFLAGS = -fopenmp

all: $(TARGET)

$(TARGET): $(SRC) Makefile
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm $(TARGET)