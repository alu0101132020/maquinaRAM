#include "instruction.hpp"

// Instrucción de carga
class LoadInstruction: public Instruction {
  public:
    LoadInstruction();
    ~LoadInstruction();
    virtual void execute() = 0;
};

// Instrucción de almacenamiento
class StoreInstruction: public Instruction {
  public:
    StoreInstruction();
    ~StoreInstruction();
    virtual void execute() = 0;
};

// Instrucción de suma
class AddInstruction: public Instruction {
  public:
    AddInstruction();
    ~AddInstruction();
    virtual void execute() = 0;
};

// Instrucción de resta
class SubInstruction: public Instruction {
  public:
    SubInstruction();
    ~SubInstruction();
    virtual void execute() = 0;
};

// Instrucción de multiplicación
class MulInstruction: public Instruction {
  public:
    MulInstruction();
    ~MulInstruction();
    virtual void execute() = 0;
};

// Instrucción de división
class DivInstruction: public Instruction {
  public:
    DivInstruction();
    ~DivInstruction();
    virtual void execute() = 0;
};

// Instrucción de lectura
class ReadInstruction: public Instruction {
  public:
    ReadInstruction();
    ~ReadInstruction();
    virtual void execute() = 0;
};

// Instrucción de escritura
class WriteInstruction: public Instruction {
  public:
    WriteInstruction();
    ~WriteInstruction();
    virtual void execute() = 0;
};

// Instrucción de salto
class JumpInstruction: public Instruction {
  public:
    JumpInstruction();
    ~JumpInstruction();
    virtual void execute() = 0;
};

// Instrucción de salto si el valor del registro 0 es igual a 0
class JumpZeInstruction: public Instruction {
  public:
    JumpZeInstruction();
    ~JumpZeInstruction();
    virtual void execute() = 0;
};

// Instrucción de salto si el valor del registro 0 es mayor a 0
class JumpGrZeInstruction: public Instruction {
  public:
    JumpGrZeInstruction();
    ~JumpGrZeInstruction();
    virtual void execute() = 0;
};

// Instrucción de parada de la máquina
class HaltInstruction: public Instruction {
  public:
    HaltInstruction();
    ~HaltInstruction();
    virtual void execute() = 0;
};

