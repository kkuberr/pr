CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC = main.cpp func.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = structs

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean run
