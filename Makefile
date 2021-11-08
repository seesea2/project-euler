CXX := g++

IncludeDir := -I src/include
CXXFLAGS := $(IncludeDir) -Wall -lm -g -std=c++17

BuildDir = ./build

cppSrc = src/main.cpp $(wildcard src/common/*.cpp) \
		$(wildcard src/euler_problems/*.cpp)
# remove the folder name src
obj = $(cppSrc:src/%.cpp=$(BuildDir)/%.o)
dep = $(obj:%.o=%.d)

.PHONY: rebuild clean BuildFolder

default: main

rebuild: clean BuildFolder main

main: $(obj) 
	$(CXX) $(CXXFLAGS) $^ -o $@  

-include $(dep)

$(BuildDir)/%.o: src/%.cpp | BuildFolder
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@ 

BuildFolder:
	@mkdir -p build
	@mkdir -p build/common
	@mkdir -p build/euler_problems

clean: 
	@rm -rf build 
	find . -name *.o -delete
	find . -name *.d -delete
