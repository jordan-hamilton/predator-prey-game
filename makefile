# Source: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Ant.o Board.o Critter.o Doodlebug.o main.o
SRCS = Ant.cpp Board.cpp Critter.cpp Doodlebug.cpp main.cpp
HEADERS = Ant.hpp Board.hpp Critter.hpp Doodlebug.hpp

groupproject: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o groupproject

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o groupproject
