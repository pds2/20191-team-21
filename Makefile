# CXX		  := g++
# CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb
# 
# BIN		:= bin
# SRC		:= src
# INCLUDE	:= include
# LIB		:= lib
# 
# LIBRARIES	:=
# EXECUTABLE	:= main
# 
# 
# all: $(BIN)/$(EXECUTABLE)
# 
# run: clean all
# 	clear
# 	./$(BIN)/$(EXECUTABLE)
# 
# $(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
# 	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)
# 
# clean:
# 	-rm $(BIN)/*

CC := g++
SRCDIR := src
TSTDIR := tests
OBJDIR := build
BINDIR := bin

MAIN := program/main.cpp
TESTER := program/tester.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))

CFLAGS := -g -Wall -O3 -std=c++11
INC := -I include/ -I third_party/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/main

tests: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(TESTER) $(TSTSOURCES) $^ -o $(BINDIR)/tester
	$(BINDIR)/tester

valgrind: main
	valgrind --leak-check=full --track-origins=yes $(BINDIR)/main

all: main

run: main
	$(BINDIR)/main

# run: clean all
# 	clear
# 	./$(BIN)/$(EXECUTABLE)
# 
# $(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
# 	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/*

.PHONY: clean coverage