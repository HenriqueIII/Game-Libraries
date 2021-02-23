CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include

#Creates list of Objects to make
ODIR 	:= obj
_OBJ = Display.o Keyboard.o DeltaTime.o Random.o Point.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

LIBRARIES   := lib

EXECUTABLE  := main

ifeq ($(OS),Windows_NT)
	TOBUILD := libUtil.dll
else
	TOBUILD := libUtil.so
endif

all: $(TOBUILD)

libUtil.dll: $(OBJ)
	$(CXX) $^ -o $@ -s -shared -Wl,--subsystem,windows,--out-implib,$(LIBRARIES)/libUtil.a -L. -l:pdcurses.a -lstdc++
	$(CXX) $(CXX_FLAGS) $(SRC)/$(EXECUTABLE).cpp -o$(BIN)/$(EXECUTABLE).exe -L lib -I include -I include/curses lib/libUtil.a -lstdc++
	copy libUtil.dll bin
	copy pdcurses.dll bin

libUtil.so: $(OBJ)
	$(CXX) $^ -shared -o $(LIBRARIES)/$@
	$(CXX) $(CXX_FLAGS) $(SRC)/$(EXECUTABLE).cpp -I$(INCLUDE) -L$(LIBRARIES) -Wl,-rpath='$$ORIGIN' -o $(BIN)/$(EXECUTABLE) -lUtil -lncurses
	cp $(LIBRARIES)/$@ $(BIN)

$(OBJ): $(ODIR)/%.o: $(SRC)/%.cpp
ifeq ($(OS),Windows_NT)
	$(CXX) -c $< -o $@ -I$(INCLUDE) -I$(INCLUDE)/curses
else
	$(CXX) -fPIC -c $< -o $@ -I$(INCLUDE)
endif

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

clean:
ifeq ($(OS),Windows_NT)
	del /F /s /q $(BIN)\* $(ODIR)\* $(LIBRARIES)\*
else
	-rm $(BIN)/* $(ODIR)/* $(LIBRARIES)/*
endif
	
