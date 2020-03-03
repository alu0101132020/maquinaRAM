/**
 * Autor: Manuel Andrés Carrera.
 * Universidad: Universidad de La Laguna.
 * Curso: 3
 * Grado: Ingeniería informática.
 * Descripción: Código que implementa la máquina RAM que es capaz de ejecutar
 *    código en lenguaje ensamblador RAM.
 */

#pragma once
#include "registers.hpp"
#include "ProgramMemory.hpp"
#include "tapes.hpp"
#include "instructionSet.hpp"
#include "instruction.hpp"
#define LOAD 0
#define STORE 1
#define ADD 2
#define SUB 3
#define MUL 4
#define DIV 5
#define READ 6
#define WRITE 7
#define JUMP 8
#define JGTZ 9
#define JZERO 10
#define HALT 11

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
