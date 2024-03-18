STANDARD = -std=c++17
CC = g++
CFLAGS = -I.
DEPS = vector.h
TARGET = test

$(TARGET): test.cpp summer_vector.h
	$(CC) $(STANDARD) -o $(TARGET) test.cpp $(CFLAGS)

 .PHONY : clean
clean :
	rm *.o $(TARGET)
