#***************************************************************
# File: Makefile
# Description:
#   Build rules for the Graph project.
#
# Notes:
#   - Compiles all .cpp files inside src/
#   - Uses headers from include/
#   - Output executable: graph
#***************************************************************

CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -O2 -Iinclude
TARGET = graph

SOURCES = $(shell find src -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

run: all
	./$(TARGET)

.PHONY: all clean run. 