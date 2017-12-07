CXX = g++
CXXFLAGS = -std=c++11

all: collision genetic

collision: md5.o ag.o main.o

genetic: md5.o ag.o mainag.o

clean:
	@$(RM) collision genetic *.o

rebuild: clean all

.PHONY: all clean rebuild
