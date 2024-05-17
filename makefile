CXX	 := g++
FLAGS := -std=c++11 -g

BIN := bin
SRC := src
INCLUDE := include

LIBS :=
EXE := interpreter.exe


all: $(BIN)/$(EXE)

run: clean all
	clear
	./$(BIN)/$(EXE)

$(BIN)/$(EXE): $(SRC)/*.cpp
	$(CXX) $(FLAGS) -I$(INCLUDE) $^ $(FLAGS) -o $@ $(LIBS)

clean:
	-rm $(BIN)/*