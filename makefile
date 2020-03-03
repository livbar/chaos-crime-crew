# Final Project - Chaos Crime Crew (C3)
# Livia Barwick 
CXX = g++
CXXFLAGS = -std=c++11

HEADERS = Agent.hpp Input_Validation.hpp Item.hpp Harem.hpp Chamber.hpp Courtyard.hpp Palace_Kitchen.hpp Simulation.hpp Space.hpp Library.hpp Treasury.hpp
SOURCES = Agent.cpp Input_Validation.cpp Item.cpp Harem.cpp Chamber.cpp Courtyard.cpp Palace_Kitchen.cpp Simulation.cpp Space.cpp Library.cpp Treasury.cpp main.cpp

c3: ${SOURCES} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SOURCES} -o c3

clean:
	rm c3
