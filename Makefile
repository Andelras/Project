AutomatedMakefile = am
CC = g++

FILES = Driver.o Random.o DiceRoll.o
EXECUTABLE = DnDToolKit.exe

PROJECT_PATH = $(PROJECT_DIR)
INC_DIRS = -I$(PROJECT_PATH)/CSC2110/
LIB_DIRS = -L$(PROJECT_PATH)/CSC2110/
LIBS = -lCSC2110

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o

all: Project	

Project: 			$(FILES)
				$(LINK) $(EXECUTABLE) $(FILES) $(LIBS)

Driver.o:			Driver.cpp Random.h
			$(COMPILE) Driver.cpp

DiceRoll.o:			DiceRoll.cpp DiceRoll.h
			$(COMPILE) DiceRoll.cpp
