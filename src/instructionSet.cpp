#include "../include/instructionSet.hpp"

LoadInstruction::LoadInstruction() {}
LoadInstruction::~LoadInstruction() {}

void LoadInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  // 0 es inmediato, 1 es directo, 2 es indirecto.
  if (typeOfDir == 0) {
    RM.setReg(0, arg);
  } else if (typeOfDir == 1) {
    RM.setReg(0, RM.getReg(arg)); 
  } else {
    RM.setReg(0, RM.getReg(RM.getReg(arg)));
  }
}

StoreInstruction::StoreInstruction() {}
StoreInstruction::~StoreInstruction() {}
void StoreInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  // 1 es directo, 2 es indirecto.
  if (typeOfDir == 1) {
    RM.setReg(arg, RM.getReg(0));
  } else if (typeOfDir == 2) {
    RM.setReg(RM.getReg(arg), RM.getReg(0)); 
  }
}

AddInstruction::AddInstruction() {}
AddInstruction::~AddInstruction() {}
void AddInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  // 0 es inmediato, 1 es directo, 2 es indirecto.
  if (typeOfDir == 0) {
    RM.setReg(0, RM.getReg(0) + arg);
  } else if (typeOfDir == 1) {
    RM.setReg(0, RM.getReg(0) + RM.getReg(arg));
  } else {
    RM.setReg(0, RM.getReg(0) + RM.getReg(RM.getReg(arg)));
  }
}

SubInstruction::SubInstruction() {}
SubInstruction::~SubInstruction() {}
void SubInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  // 0 es inmediato, 1 es directo, 2 es indirecto.
  if (typeOfDir == 0) {
    RM.setReg(0, RM.getReg(0) - arg);
  } else if (typeOfDir == 1) {
    RM.setReg(0, RM.getReg(0) - RM.getReg(arg));
  } else {
    RM.setReg(0, RM.getReg(0) - RM.getReg(RM.getReg(arg)));
  }
}

MulInstruction::MulInstruction() {}
MulInstruction::~MulInstruction() {}
void MulInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  // 0 es inmediato, 1 es directo, 2 es indirecto.
  if (typeOfDir == 0) {
    RM.setReg(0, RM.getReg(0) * arg);
  } else if (typeOfDir == 1) {
    RM.setReg(0, RM.getReg(0) * RM.getReg(arg));
  } else {
    RM.setReg(0, RM.getReg(0) * RM.getReg(RM.getReg(arg)));
  }
}

DivInstruction::DivInstruction() {}
DivInstruction::~DivInstruction() {}
void DivInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  // 0 es inmediato, 1 es directo, 2 es indirecto.
  if (typeOfDir == 0) {
    if (arg != 0){
      RM.setReg(0, RM.getReg(0) / arg);
    } else {
      std::cerr << "Error en la línea " << PC << ": no están permitidas divisiones entre 0.";
      throw  "Error"; 
    }
  } else if (typeOfDir == 1) {
    if (RM.getReg(arg) != 0) {
      RM.setReg(0, RM.getReg(0) / RM.getReg(arg));
    } else {
      std::cerr << "Error en la línea " << PC << ": no están permitidas divisiones entre 0.";
      throw  "Error"; 
    }  
  } else {
    if (RM.getReg(RM.getReg(arg) != 0)) {
      RM.setReg(0, RM.getReg(0) / RM.getReg(RM.getReg(arg)));
    } else {
      std::cerr << "Error en la línea " << PC << ": no están permitidas divisiones entre 0.";
      throw  "Error"; 
    }
  }
}

ReadInstruction::ReadInstruction() {}
ReadInstruction::~ReadInstruction() {}
void ReadInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  // 1 es directo, 2 es indirecto.
  if (typeOfDir == 1) {
    RM.setReg(arg, RT.read());
  } else if (typeOfDir == 2) {
    RM.setReg(RM.getReg(arg), RT.read());
  }
}

WriteInstruction::WriteInstruction() {}
WriteInstruction::~WriteInstruction() {}
void WriteInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  // 0 es inmediato, 1 es directo, 2 es indirecto.
  if (typeOfDir == 0) {
    WT.write(arg);
  } else if (typeOfDir == 1) {
    WT.write(RM.getReg(arg));
  } else {
    WT.write(RM.getReg(RM.getReg(arg)));
  }
}

// En las instrucciones de saltos restamos 1 a la instrucción porque el program Counter siempre avanzará 1 posición
// y de no hacerlo podríamos perder una instrucción que esté en la misma línea que la etiqueta
JumpInstruction::JumpInstruction() {}
JumpInstruction::~JumpInstruction() {}
void JumpInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  PC = arg - 1;
}

JumpZeInstruction::JumpZeInstruction() {}
JumpZeInstruction::~JumpZeInstruction() {}
void JumpZeInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  if (RM.getReg(0) == 0) {
    PC = arg -1;
  }
}

JumpGrZeInstruction::JumpGrZeInstruction() {}
JumpGrZeInstruction::~JumpGrZeInstruction() {}
void JumpGrZeInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  if (RM.getReg(0) > 0) {
    PC = arg - 1;
  }
}

HaltInstruction::HaltInstruction() {}
HaltInstruction::~HaltInstruction() {}
void HaltInstruction::execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) {
  PC = -2;
  WT.writeOnFile();
}