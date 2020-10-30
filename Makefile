CC    = g++
FLAGS        = -std=c++11
CFLAGS       = -fPIC -g -Wall -Wextra
LDFLAGS      = -W
LIBS += -lboost_system -ldl -lboost_filesystem
SUBDIRS = $(shell ls -d */)

DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

TARGET  = pluginTest
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)
	for dir in $(SUBDIRS) ; do \
		make -C  $$dir ; \
	done

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		make clean -C  $$dir ; \
	done
