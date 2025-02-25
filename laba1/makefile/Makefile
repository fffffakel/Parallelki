CXX = g++
TARGET = sum
SRC = ../main.cpp

ifeq ($(TYPE), double)
	CXXFLAGS += -DUSE_DOUBLE
endif

all: $(TARGET)

$(TARGET): $(SRC) Makefile
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm $(TARGET)