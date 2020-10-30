CC    = g++
FLAGS        = # -std=gnu99 -Iinclude
CFLAGS       = -fPIC -g #-pedantic -Wall -Wextra -ggdb3
LDFLAGS      = -shared

DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

TARGET  = libPlugin1.so
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)


all: $(TARGET)

$(TARGET):
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	@rm -f $(TARGET)
