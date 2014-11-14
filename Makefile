# Make file for leetcode questions
CXX = g++ -Wno-deprecated -Wformat -Wsign-compare -Wmaybe-uninitialized 
OPT ?= -g -O3
CXXFLAG += -I../include -Wall $(OPT) 

CC = g++ -Wall

 
SOURCE = ./

OBJS = 	./minStack.o \

all: main

$(SOURCE)/%.o: $(SOURCE)/%.cpp $(SOURCE)/%.h
	${CXX} ${CXXFLAG} -c $< -o $@ 
$(SOURCE)/%.o: $(SOURCE)/%.c $(SOURCE)/%.h
	${CXX} ${CXXFLAG} -c $< -o $@ 

main: main.o ${OBJS} ${DLL}
	${CXX} ${CXXFLAG} ${OBJS} main.o -o main  
%.o: %.cpp
	${CXX} ${CXXFLAG} -c $< -o $@

clean:
	@rm -fr *.o ${SOURCE}/*.o ${SOURCE}/*.h.gch
