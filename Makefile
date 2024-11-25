CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = HuffmanCompressionTool
SRC = src/main.cpp src/HuffmanCoding.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
