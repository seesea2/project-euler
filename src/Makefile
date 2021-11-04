CXX := g++

IncludeDir := -I include
CXXFLAGS := $(IncludeDir) -Wall -lm 

BuildDir = ./build

cppSrc = main.cpp $(wildcard common/*.cpp) \
		$(wildcard euler_problems/*.cpp)
obj = $(cppSrc:%.cpp=$(BuildDir)/%.o)
dep = $(obj:%.o=%.d)

.PHONY: rebuild clean BuildFolder

default: main

rebuild: clean BuildFolder main

main: $(obj) 
	$(CXX) $(CXXFLAGS) $^ -o $@  

-include $(dep)

$(BuildDir)/%.o: %.cpp | BuildFolder
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@ 

BuildFolder:
	@mkdir -p build
	@mkdir -p build/common
	@mkdir -p build/euler_problems

clean: 
	@rm -rf build 
