SYSTEMC_DIR = /usr/local/systemc-2.3.3
PROJECT     = adder
BUILDFLAGS  = -g3
CXX         = g++

INCFLAGS    = -I. -I${SYSTEMC_DIR}/include
LDFLAGS     = -L${SYSTEMC_DIR}/lib-linux64 -lsystemc -lm -Wl,-rpath,/usr/local/systemc-2.3.3/lib-linux64
SRC_CPPHEAD = HalfAdder FullAdder
SRC_CPP     =
HEADERS     =
MAIN        = main.cpp
OBJECTS     = $(SRC_CPPHEAD:=.o) $(SRC_CPP:cpp=o)

EXE = $(PROJECT)

all: $(EXE)

$(EXE): $(MAIN) $(OBJECTS) $(HEADERS)
	@echo "$@ building..."
	$(CXX) $(INCFLAGS) $(MAIN) $(OBJECTS) $(LDFLAGS) -o $@
	@echo ""
	@echo "$@ build done successfully..."
	@echo ""

%.o:%.cpp %.h
	@echo "Compiling $< ..."
	$(CXX) -c $< $(INCFLAGS)

clean:
	rm -f $(EXE)
	rm -f *.o
