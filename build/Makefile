IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++17 -g

ODIR=../src

.PHONY: all

_OBJ = RAMMachine.o validInstructions.o registers.o ProgramMemory.o taps.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: RAM


$(ODIR)/RAMMachine.o: $(ODIR)/RAMMachine.cpp $(IDIR)/RAMMachine.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/validInstructions.o: $(ODIR)/validInstructions.cpp $(IDIR)/validInstructions.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/registers.o: $(ODIR)/registers.cpp $(IDIR)/registers.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/ProgramMemory.o: $(ODIR)/ProgramMemory.cpp $(IDIR)/ProgramMemory.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/taps.o: $(ODIR)/taps.cpp $(IDIR)/taps.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

# $(ODIR)/instruction.o: $(ODIR)/instruction.cpp $(IDIR)/instruction.hpp
# 	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)


RAM: $(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS)




.PHONY: clean

clean:
	rm -f $(ODIR)/*.o ./P1
