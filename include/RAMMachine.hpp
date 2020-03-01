#pragma once
#include "registers.hpp"
#include "ProgramMemory.hpp"
#include "tapes.hpp"
#include "instructionSet.hpp"
#include "instruction.hpp"

class RAMMachine {
  private:
    RegisterMemory registerMemory;
    ProgramMemory programMemory;
    WriteTape writeTape;
    ReadTape readTape;
    Instruction *currentInstruction;
    int programCounter;
    int executedInstructions;
  public:
    RAMMachine(std::string &ramFile, std::string &inputFile, std::string &outputFile);
    void writeState();
    void execute();
    void executeOneStep();
    void debugMode();
    void executeOneInstruct();
    void start(bool debugModeFlag = 0);
    void restart();
};
