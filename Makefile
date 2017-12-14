CXX = g++
CXXFLAGS = -Ofast -std=c++11 -Wall

all: genetic

genetic: md5.o cryptohash.o ag.o mainag.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	@$(RM) genetic *.o

rebuild: clean all

.PHONY: all clean rebuild
