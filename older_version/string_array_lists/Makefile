CXX = g++
TARGET = main
OBJ = main.o string_function.o
CXXFLAGS = -c -Wall 

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.c
	$(CXX) $(CXXFLAGS) $< -o $@

.PYONE: clean

clean:
	rm -f *.o $(TARGET)