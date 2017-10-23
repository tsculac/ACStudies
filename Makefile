OBJSRUN = Functions.o Settings.o Analyzer.o run.o
OBJSDUMP = Functions.o Settings.o Analyzer.o DumpPlots.o
OBJSEFF = Functions.o Settings.o Analyzer.o EfficiencyVsCut.o
OBJSCAT = Functions.o Settings.o Analyzer.o Categorisation.o
OBJSSLICE = Functions.o Settings.o Analyzer.o M4lSlices.o
OBJSSPLINES = Functions.o Settings.o Analyzer.o ProduceSplines.o

CXXFLAGS = -g -I. -m64 $(shell root-config --cflags)
LDFLAGS = $(shell root-config --libs)
CXX = g++

all: run DumpPlots EfficiencyVsCut Categorisation Slices ProduceSplines

run: ${OBJSRUN}
	${CXX} ${LDFLAGS} ${CXXFLAGS} ${OBJSRUN} -o run

DumpPlots: ${OBJSDUMP}
	${CXX} ${LDFLAGS} ${CXXFLAGS} ${OBJSDUMP} -o DumpPlots

EfficiencyVsCut: ${OBJSEFF}
	${CXX} ${LDFLAGS} ${CXXFLAGS} ${OBJSEFF} -o EfficiencyVsCut

Categorisation: ${OBJSCAT}
	${CXX} ${LDFLAGS} ${CXXFLAGS} ${OBJSCAT} -o Categorisation

Slices: ${OBJSSLICE}
	${CXX} ${LDFLAGS} ${CXXFLAGS} ${OBJSSLICE} -o Slice

ProduceSplines: ${OBJSSPLINES}
	${CXX} ${LDFLAGS} ${CXXFLAGS} ${OBJSSPLINES} -o ProduceSplines

################################
Analyzer.o: Analyzer.C
	${CXX} -c ${CXXFLAGS} $^

Settings.o: Settings.C
	${CXX} -c ${CXXFLAGS} $^

Functions.o: Functions.C
	${CXX} -c ${CXXFLAGS} $^

run.o: run.cpp
	${CXX} -c ${CXXFLAGS} run.cpp

DumpPlots.o: DumpPlots.cpp
	${CXX} -c ${CXXFLAGS} DumpPlots.cpp

EfficiencyVsCut.o: EfficiencyVsCut.cpp
	${CXX} -c ${CXXFLAGS} EfficiencyVsCut.cpp

Categorisation.o: Categorisation.cpp
	${CXX} -c ${CXXFLAGS} Categorisation.cpp

M4lSlices.o: M4lSlices.C
	${CXX} -c ${CXXFLAGS} M4lSlices.C

ProduceSplines.o: ProduceSplines.cpp
	${CXX} -c ${CXXFLAGS} ProduceSplines.cpp
################################

# ==========================================
clean:
	\rm *.o run DumpPlots EfficiencyVsCut Categorisation Slice ProduceSplines