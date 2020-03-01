#include "../include/RAMMachine.hpp"

RAMMachine::RAMMachine(std::string &ramFile, std::string &inputFile, std::string &outputFile) :
    programMemory(ramFile), readTape(inputFile), writeTape(outputFile),
    programCounter(0), registerMemory(10), currentInstruction(nullptr), executedInstructions(0) {}

void RAMMachine::start(bool debugModeFlag) {
  if (debugModeFlag) {
    debugMode();
  } else {
    // std::cout << "\t\t---- ESTADO INICIAL ----\n\n";
    // writeState();
    execute();
    // std::cout << "\t\t---- ESTADO FINAL ----\n\n";
    // writeState();
    std::cout << "El programa ha ejecutado " << executedInstructions << " instrucciones.\n\n";
  }
}

void RAMMachine::writeState() {
  std::cout << "---------- Registros -----------\n\n";
  registerMemory.writeRegisters();
  std::cout << "---------- Cinta de escritura -----------\n\n";
  writeTape.showTape();
  std::cout << "---------- Cinta de lectura -----------\n\n";
  readTape.showTape();
  std::cout << "---------- Programa -----------\n\n";
  programMemory.writeProgram();
  std::cout << "\n\n";
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
        currentInstruction = new JumpGrZeInstruction;
        break;     
      case 10:
        currentInstruction = new JumpZeInstruction;
        break; 
      case 11:
        currentInstruction = new HaltInstruction;
        break;
      default:
       currentInstruction = nullptr;
    }
    if (currentInstruction != nullptr) {
      currentInstruction->execute(registerMemory, writeTape, readTape, typeOfDir, argumentOfInst, programCounter);
      delete currentInstruction;
    } else {
      throw "error";
    }
    programCounter++;
    executedInstructions++;
  }
}

void RAMMachine::executeOneInstruct() {
    if (programCounter != -1 && programCounter < programMemory.numbOfLines()) {
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
        currentInstruction = new JumpGrZeInstruction;
        break;     
      case 10:
        currentInstruction = new JumpZeInstruction;
        break; 
      case 11:
        currentInstruction = new HaltInstruction;
        break;
      default:
       currentInstruction = nullptr;
    }
    if (currentInstruction != nullptr) {
      currentInstruction->execute(registerMemory, writeTape, readTape, typeOfDir, argumentOfInst, programCounter);
      delete currentInstruction;
    } else {
      throw "error";
    }
    programCounter++;
    executedInstructions++;
  } else {
    std::cout << "El programa ha llegado a su final.\n";
  }
}

void RAMMachine::debugMode() {
  char option = 'q';
  do {
    std::cout << ">";
    std::cin >> option;
    if(option == 'h') {
    std::cout << "--- DEBUG MODE ---\n";
    std::cout << "r: Ver los registros\n";
    std::cout << "t: Traza\n";
    std::cout << "e: Ejecutar\n";
    std::cout << "s: Desensamblador\n";
    std::cout << "i: Ver cinta de entrada\n";
    std::cout << "o: Ver cinta de salida\n";
    std::cout << "h: Ayuda\n";
    std::cout << "x: Salir\n";
    }
    switch (option) {
      case ('r'):
        registerMemory.writeRegisters();
        break;
      case ('t'):
        executeOneInstruct();
        break;
      case ('e'):
        execute();
        break;
      case ('s'):
        programMemory.disassemble();
        break;
      case ('i'):
        readTape.showTape();
        break;
      case ('o'):
        writeTape.showTape();
        break;
      case ('h'):
        break;
      case ('x'):
        break;
      default:
        std::cout << "Opción no permitida\n";
        break;
    }
  } while(option != 'x');
}