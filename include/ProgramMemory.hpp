/**
 * Autor: Manuel Andrés Carrera.
 * Universidad: Universidad de La Laguna.
 * Curso: 3
 * Grado: Ingeniería informática.
 * Descripción: Código que implementa la memoria del programa de la máquina
 *    RAM, almacenada como un vector de tuplas para cada una de las instrucciones
 *    y un vector de parejas que contiene las etiquetas del programa.
 */

#pragma once
#include <vector>
#include <tuple>
#include <algorithm>

#include "validInstructions.hpp"

class ProgramMemory {
  private:
    //Tuplas que almacenan códigod e instrucción, tipo de instrucción/direcc. y valor del parámetro.
    std::vector <std::tuple <int, int, int> >  lines; 
    //Parejas que almacenan los nombres de las etiquetas y sus líneas
    std::vector <std::pair <std::string, int > > tags;
    ValidInstructions VI;
    int actualLine;

  public:
    ProgramMemory(const std::string &file);
    ~ProgramMemory();

    std::tuple <int, int, int> getLine(const int &index);
    void setLine(const int &index, std::tuple < int, int, int> &value);
    std::vector < std::tuple <int, int, int> > getAllProgram();
    int numbOfLines(void);
    void writeProgram();
    std::string typeOfInstruction(int number);
    void findTags(const std::string &file);
    void buildProgram(const std::string &file);
    int lineOfTag(std::string tagName);
    std::string nameOfTag(int tagLine);
    ValidInstructions getVI();
    void disassemble();
    bool taggedLine(int numberLine);
};
