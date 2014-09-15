CXX = g++ -g -std=c++0x
CHECKSTYLE = python ../cpplint.py
MAIN = $(basename $(wildcard *Main.cpp))
TEST = $(basename $(wildcard *Test.cpp))
OBJECTS = $(addsuffix .o, $(filter-out %Main %Test, $(basename $(wildcard *.cpp))))
HEADERS = $(wildcard *.h)
LIBS = -lncurses

.PRECIOUS: %.o

all: compile test checkstyle

compile: $(MAIN) $(TEST)

test: compile
	g++ -g -std=c++0x -o PooSweeperStateTest PooSweeperStateTest.o PooSweeperState.o -lncurses -lgtest -lgtest_main -lpthread
	./PooSweeperStateTest
checkstyle:
	$(CHECKSTYLE) *.cpp *.h

%Main: %Main.o $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

%Test: %Test.o $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS) -lgtest -lgtest_main -lpthread

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f *.o
	rm -f $(MAIN)
	rm -f $(TEST)
git: 
	git add . 
	git status
	git commit
