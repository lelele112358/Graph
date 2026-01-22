# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source files
SRC = src/main.cpp \
      src/Matrix_Implementation_Graph.cpp \
      src/List_Implementation_Graph.cpp

# Output executable
TARGET = graph

# Default target
all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean up compiled files
clean:
	rm -f $(TARGET)
