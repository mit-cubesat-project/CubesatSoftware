
CXX=g++
INCLUDES=-I$(PIXELINK_SDK_INC)
LIBPATH=-L$(PIXELINK_SDK_LIB) 
DEFINES=-DPIXELINK_LINUX

CPPFLAGS=-O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP $(DEFINES) $(INCLUDES)
LIBS=-lPxLApi

###
# Add OpenCV
CPPFLAGS += `pkg-config --cflags opencv`
LIBS += `pkg-config --libs opencv`

SRCFILES=getSnapshot.cpp
OBJFILES=$(SRCFILES:.cpp=.o)

all: getSnapshot

getSnapshot : $(OBJFILES) 
	rm -f $@
	$(CXX) $(LIBPATH) -o $@ $^ $(LIBS)

.cpp.o:
	$(CXX) $(CPPFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf getSnapshot


