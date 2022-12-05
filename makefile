CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla
EXEC = biquadris
OBJECTS = main.o board.o square.o abstractlevel.o levelzero.o block.o blockpart.o tblock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean