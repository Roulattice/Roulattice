CCOMP = gcc
OPT = -m64 -O3 -Wall -lm -std=c99 # linux (Ubuntu) version

ifeq "$(OSTYPE)" "darwin"
OPT = -m64 -O3 -Wall # MacOS X version
endif


INCLUDE = include
SRC = src
BIN = bin

vpath %.h $(INCLUDE)
vpath %.o $(BIN)
vpath %.c $(SRC)
.SUFFIXES:
PROGRAMS = Roulattice
ROUL_C = main.o getArgs.o license.o output.o read_dcd.o time.o observables.o pair_correlation_function.o statistics.o entropy.o bricks.o checks.o random_knuth.o tetra_rw.o tetra_fww.o tetra_saw1.o tetra_fsaw1.o tetra_bsaw1.o tetra_fbsaw1.o tetra_saw2.o tetra_fsaw2.o tetra_bsaw2.o tetra_fbsaw2.o tetra_saw3.o tetra_fsaw3.o tetra_bsaw3.o tetra_fbsaw3.o intra_potential.o SASA.o


DEPENDFILE = .depend
SOURCES = $(wildcard $(SRC)/*.c)

all: depend $(PROGRAMS)

depend: $(SOURCES)
	$(CCOMP) -I$(INCLUDE) -MM $(SOURCES) > $(DEPENDFILE)

$(BIN):
	mkdir -p $(BIN)

Roulattice: $(ROUL_C)
	$(CCOMP) -o Roulattice $(patsubst %.o,$(BIN)/%.o,$(ROUL_C)) $(OPT)


%.o: %.c $(BIN)
	$(CCOMP) -I$(INCLUDE) -o $(BIN)/$@ -c $< $(OPT)

clean :
	rm -f $(BIN)/*.o
	rm -df $(BIN)
	for i in . $(SRC) $(INCLUDE); do rm -f $$i/*~; done
	for i in $(PROGRAMS); do rm -f $$i; done
