CXX = g++
CXXFLAGS = -Ofast -std=c++11 -Wall

all: collision genetic

collision: md5.o cryptohash.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

genetic: md5.o cryptohash.o ag.o mainag.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	@$(RM) collision genetic *.o

rebuild: clean all

.PHONY: all clean rebuild
