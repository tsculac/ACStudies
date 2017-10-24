CXXFLAGS = -g -I. -m64 $(shell root-config --cflags) -I include
LDFLAGS = $(shell root-config --libs) -lm -lGenVector
CXX = g++

VPATH = ./src/ ./include/

SRCPP_RUN = run.cpp\
		Analyzer.cpp\
		Settings.cpp\
		Functions.cpp\

SRCPP_DUMP = DumpPlots.cpp\
		Analyzer.cpp\
		Settings.cpp\
		Functions.cpp\

SRCPP_EFF = EfficiencyVsCut.cpp\
		Analyzer.cpp\
		Settings.cpp\
		Functions.cpp\

SRCPP_CAT = Categorisation.cpp\
		Analyzer.cpp\
		Settings.cpp\
		Functions.cpp\

SRCPP_SLICE = M4lSlices.cpp\
		Analyzer.cpp\
		Settings.cpp\
		Functions.cpp\

SRCPP_SPLINES = ProduceSplines.cpp\
		Analyzer.cpp\
		Settings.cpp\
		Functions.cpp\

SRCPP_NJETS = NJetsVBF.cpp\
		Analyzer.cpp\
		Settings.cpp\
		Functions.cpp\

INCLUDES = run.h\
	        Analyzer.h\
        	Settings.h\
		Functions.h\
    
OBJCPP_RUN = $(patsubst %.cpp,obj/%.o,$(SRCPP_RUN))
OBJCPP_DUMP = $(patsubst %.cpp,obj/%.o,$(SRCPP_DUMP))
OBJCPP_EFF = $(patsubst %.cpp,obj/%.o,$(SRCPP_EFF))
OBJCPP_CAT = $(patsubst %.cpp,obj/%.o,$(SRCPP_CAT))
OBJCPP_SLICE = $(patsubst %.cpp,obj/%.o,$(SRCPP_SLICE))
OBJCPP_SPLINES = $(patsubst %.cpp,obj/%.o,$(SRCPP_SPLINES))
OBJCPP_NJETS = $(patsubst %.cpp,obj/%.o,$(SRCPP_NJETS))

all: run DumpPlots EfficiencyVsCut Categorisation Slices ProduceSplines NJetsVBF


obj/%.o: %.cpp $(INCLUDES)
	@echo ">> compiling $*"
	@mkdir -p obj/
	@$(CXX) -c $< ${CXXFLAGS} -o $@
   

run: $(OBJCPP_RUN)
	@echo ">> linking..."
	@$(CXX) $^ $(EXTLIBS) ${LDFLAGS} ${CXXFLAGS}  -o $@

DumpPlots: $(OBJCPP_DUMP)
	@echo ">> linking..."
	@$(CXX) $^ $(EXTLIBS) ${LDFLAGS} ${CXXFLAGS}  -o $@

EfficiencyVsCut: $(OBJCPP_EFF)
	@echo ">> linking..."
	@$(CXX) $^ $(EXTLIBS) ${LDFLAGS} ${CXXFLAGS}  -o $@

Categorisation: $(OBJCPP_CAT)
	@echo ">> linking..."
	@$(CXX) $^ $(EXTLIBS) ${LDFLAGS} ${CXXFLAGS}  -o $@

Slices: $(OBJCPP_SLICE)
	@echo ">> linking..."
	@$(CXX) $^ $(EXTLIBS) ${LDFLAGS} ${CXXFLAGS}  -o $@

ProduceSplines: $(OBJCPP_SPLINES)
	@echo ">> linking..."
	@$(CXX) $^ $(EXTLIBS) ${LDFLAGS} ${CXXFLAGS}  -o $@

NJetsVBF: $(OBJCPP_NJETS)
	@echo ">> linking..."
	@$(CXX) $^ $(EXTLIBS) ${LDFLAGS} ${CXXFLAGS}  -o $@


clean:
	@echo ">> cleaning objects and executable"
	@rm -f obj/*.o
	@rm -f run DumpPlots EfficiencyVsCut Categorisation Slices ProduceSplines NJetsVBF
