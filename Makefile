CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = SRC = src/main.cpp \
      src/Matrix_Implementation_Graph.cpp \
      src/List_Implementation_Graph.cpp

TARGET = graph

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
