# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source files
SRC = src/main.cpp \
      src/GraphFactory.cpp \
      src/Graph_Bipartite.cpp \
      src/Matrix_Implementation_Graph.cpp \
      src/List_Implementation_Graph.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Output executable
TARGET = graph

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
