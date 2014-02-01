CC=echo ":::!BUILDING!:::" && g++
CFLAGS=-g -c -w -Wall 
HEADERS=main.h player.h draw.h scene.h physics.h level.h
SOURCES=main.cpp player.cpp draw.cpp scene.cpp physics.cpp level.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=run

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
LDFLAGS= -lGL -lGLU -lSDL -lSDL_image -lSDL_ttf
endif
ifeq ($(UNAME), Darwin)
LDFLAGS= -framework OpenGL -framework GLUT -lboost_system-mt -lboost_timer-mt
endif


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.gch *.o run
.PHONY: clean
