CXX = g++
TARGET = task3.1
SRC = task3.1.cpp
CXXFLAGS = -fopenmp

all: $(TARGET)

$(TARGET): $(SRC) Makefile
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm $(TARGET)