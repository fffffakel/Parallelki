CXX = g++
TARGET = task3.2
SRC = task3.2.cpp
CXXFLAGS = -fopenmp

all: $(TARGET)

$(TARGET): $(SRC) Makefile
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm $(TARGET)