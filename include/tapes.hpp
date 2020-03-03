/**
 * Autor: Manuel Andrés Carrera.
 * Universidad: Universidad de La Laguna.
 * Curso: 3
 * Grado: Ingeniería informática.
 * Descripción: Código de las distintas cintas que usa la máquina RAM,
 *    concretamente una de escritura, una de lectura y una por defecto.
 */

#pragma once
#include <vector>
#include <fstream>
#include <iostream>

class Tape {
  protected:
    std::vector<int> elements;
    int head;
    void moveForward();
  public:
    Tape();
    ~Tape();
    void showTape();
    Tape getTape(void);
    void resetTape(void);
};

class ReadTape : public Tape {
  public:
    ReadTape(std::string &file);
    int read();
    void load(std::string &file);
};

class WriteTape : public Tape {
  private:
    std::string outputFile;
  public:
    WriteTape(std::string &file);
    void write(const int &number);
    void writeOnFile();
    int elementsWritten();
    void resetWTape(void);
};
