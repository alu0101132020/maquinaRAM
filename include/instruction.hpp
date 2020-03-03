/**
 * Autor: Manuel Andrés Carrera.
 * Universidad: Universidad de La Laguna.
 * Curso: 3
 * Grado: Ingeniería informática.
 * Descripción: Código que implementa la estructura básica de las instrucciones
 *    de la máqunia RAM.
 */

#pragma once
#include "tapes.hpp"
#include "registers.hpp"

class Instruction {
  public:
    Instruction();
    ~Instruction();
    virtual void execute(RegisterMemory &RM, WriteTape &WT, ReadTape &RT, const int &typeOfDir, int &arg, int &PC) = 0;
};

