#pragma once
#include "instruction.hpp"

// Instrucción de carga
class LoadInstruction: public Instruction {
  public:
    LoadInstruction();
    ~LoadInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de almacenamiento
class StoreInstruction: public Instruction {
  public:
    StoreInstruction();
    ~StoreInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de suma
class AddInstruction: public Instruction {
  public:
    AddInstruction();
    ~AddInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de resta
class SubInstruction: public Instruction {
  public:
    SubInstruction();
    ~SubInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de multiplicación
class MulInstruction: public Instruction {
  public:
    MulInstruction();
    ~MulInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de división
class DivInstruction: public Instruction {
  public:
    DivInstruction();
    ~DivInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de lectura
class ReadInstruction: public Instruction {
  public:
    ReadInstruction();
    ~ReadInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de escritura
class WriteInstruction: public Instruction {
  public:
    WriteInstruction();
    ~WriteInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de salto
class JumpInstruction: public Instruction {
  public:
    JumpInstruction();
    ~JumpInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de salto si el valor del registro 0 es igual a 0
class JumpZeInstruction: public Instruction {
  public:
    JumpZeInstruction();
    ~JumpZeInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de salto si el valor del registro 0 es mayor a 0
class JumpGrZeInstruction: public Instruction {
  public:
    JumpGrZeInstruction();
    ~JumpGrZeInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};

// Instrucción de parada de la máquina
class HaltInstruction: public Instruction {
  public:
    HaltInstruction();
    ~HaltInstruction();
    void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC);
};
