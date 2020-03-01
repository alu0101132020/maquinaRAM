#pragma once
#include "tapes.hpp"
#include "registers.hpp"

class Instruction {
  public:
    Instruction();
    ~Instruction();
    virtual void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) = 0;
};

