IDIR := ./include
CXX := g++
CXXFLAGS := -Wall -lm -I$(IDIR)

cppSrc = $(wildcard src/*.cpp) $(wildcard src/common/*.cpp) \
					$(wildcard src/1_50/*.cpp) \
					$(wildcard src/51_100/*.cpp) $(wildcard src/101_150/*.cpp) \
					$(wildcard src/501_550/*.cpp) $(wildcard src/551_600/*.cpp)
obj = $(cppSrc:.cpp=.o)

main: $(obj) 
	$(CXX) -o $@ $^ $(CXXFLAGS)


.PHONY: clean
clean: 
	rm -f $(obj) **/*.o main