/**
 * Autor: Manuel Andrés Carrera.
 * Universidad: Universidad de La Laguna.
 * Curso: 3
 * Grado: Ingeniería informática.
 * Descripción: Código que implementa la memoria de registros de la máquina
 *   RAM almacenada en un vector de elementos (registros).
 */

#pragma once

#include <vector>
#include <iostream>

class RegisterMemory {
  private:
    std::vector<long long> regist;
  public:
    RegisterMemory();
    RegisterMemory(const int &number);
    ~RegisterMemory();

    long long getReg(const int &number);
    void setReg(const int &index, int value);
    int numbOfReg(void);
    void writeRegisters();
    std::vector<long long> getAllReg();
    void cleanRegisters(void);
    // friend std::ostream& operator<<(std::ostream& os, RegisterMemory& dt);
};
