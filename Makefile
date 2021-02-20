CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := 

LIBRARIES   := lib
#lib/libncurses.so \
	lib/libPoint.so \
	lib/libRandom.so \
	lib/libDisplay.so \
	lib/libKeyboard.so \
	lib/libDeltaTime.so

EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) $^ -o $@ -L$(LIBRARIES) -Wl,-rpath=$(LIBRARIES)/ \
	-lncurses -lPoint -lRandom -lDisplay -lKeyboard -lDeltaTime

clean:
	-rm $(BIN)/*
