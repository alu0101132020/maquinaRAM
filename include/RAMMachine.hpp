#include "registers.hpp"
#include "ProgramMemory.hpp"
#include "taps.hpp"

class RAMMachine {
  private:
    RegisterMemory registerMemory;
    ProgramMemory programMemory;
    WriteTape writeTape;
    ReadTape readTape;
    //Instruction *Instruction;
    int programCounter;

  public:
    RAMMachine(std::string &ramFile, std::string &inputFile, std::string &outputFile);
    void writeState();
};
