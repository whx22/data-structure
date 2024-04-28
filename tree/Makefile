# # VERSION 1
# CXX = g++
# TARGET = main
# OBJ = main.o expression_conversion.o expression_calculation.o

# $(TARGET): $(OBJ)
# 	$(CXX) -o $(TARGET) $(OBJ) 

# main.o: main.cpp
# 	$(CXX) -c main.cpp

# expression_conversion.o: expression_conversion.cpp
# 	$(CXX) -c expression_conversion.cpp

# expression_calculation.o: expression_calculation.cpp
# 	$(CXX) -c expression_calculation.cpp

# VERSION 2
CXX = g++
TARGET = main
OBJ = main.o expression_conversion.o expression_calculation.o
CXXFLAGS = -c -Wall

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^
# $@ : target file
# $^ : all of dependent files

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
# $< : the first dependent file

.PHONY: clean
clean: 
	rm -f *.o $(TARGET)