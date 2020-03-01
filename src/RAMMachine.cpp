#include "../include/RAMMachine.hpp"

RAMMachine::RAMMachine(std::string &ramFile, std::string &inputFile, std::string &outputFile) :
    programMemory(ramFile), readTape(inputFile), writeTape(),
    programCounter(0), registerMemory(30), currentInstruction(nullptr) {}

void RAMMachine::writeState() {
  std::cout << "---------- Registros -----------\n\n";
  registerMemory.writeRegisters();
  std::cout << "---------- Cinta de escritura -----------\n\n";
  writeTape.showTape();
  std::cout << "---------- Cinta de lectura -----------\n\n";
  readTape.showTape();
  std::cout << "---------- Programa -----------\n\n";
  programMemory.writeProgram();
}

void RAMMachine::execute() {
  while(programCounter != -1 && programCounter < programMemory.numbOfLines()) {
    auto currentLine = programMemory.getLine(programCounter);
    int typeOfInst = std::get<0>(currentLine);
    int typeOfDir = std::get<1>(currentLine);
    int argumentOfInst = std::get<2>(currentLine);
    switch (typeOfInst) {
      case 0:
        currentInstruction = new LoadInstruction;
        break;
      case 1:
        currentInstruction = new StoreInstruction;
        break;
      case 2:
        currentInstruction = new AddInstruction;
        break;
      case 3:
        currentInstruction = new SubInstruction;
        break;      
      case 4:
        currentInstruction = new MulInstruction;
        break;
      case 5:
        currentInstruction = new DivInstruction;
        break;  
      case 6:
        currentInstruction = new ReadInstruction;
        break;
      case 7:
        currentInstruction = new WriteInstruction;
        break;     
      case 8:
        currentInstruction = new JumpInstruction;
        break;
      case 9:
        currentInstruction = new JumpZeInstruction;
        break;      
      case 10:
        currentInstruction = new JumpGrZeInstruction;
        break;
      case 11:
        currentInstruction = new HaltInstruction;
        break;
      default:
       currentInstruction = nullptr;
    }
    if (currentInstruction != nullptr) {
      currentInstruction->execute(registerMemory, writeTape, readTape, typeOfInst, argumentOfInst, programCounter);
    }
    programCounter++;
  }
}
