CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = MazeMain.o MazeNode.o MazeNodeHelper.o

SRCS = MazeMain.cpp MazeNode.cpp MazeNodeHelper.cpp

HEADERS = MazeNode.hpp MazeNodeHelper.hpp

AS9_p1: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -lncurses -o AS9

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
