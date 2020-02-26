#include "../include/ProgramMemory.hpp"



std::string stringToUpper(std::string &str)
{
  std::transform(str.begin(), str.end(),str.begin(), ::toupper);
}

std::string & ltrim(std::string & str)
{
  auto it2 =  std::find_if( str.begin() , str.end() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
  str.erase( str.begin() , it2);
  return str;
}

std::string & rtrim(std::string & str)
{
  auto it1 =  std::find_if( str.rbegin() , str.rend() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
  str.erase( it1.base() , str.end() );
  return str;
}

ProgramMemory::ProgramMemory(const std::string &file) :
   VI("instrucciones.txt") {
       std::ifstream inFile;
       inFile.open(file);
       if (!inFile) {
         std::cout << "Unable to open file";
         exit(1); // terminate with error
       }
       std::string line;
  

       while (getline(inFile, line)) {
          std::string instCode = "";
          std::string arg = "";
          int opt = -1; // Opciones que puede tener una instrucción, 0 sin argumentos, 1 direccionamiento inmediato, 2 direccionamiento directo, 3 direccionamiento indirecto.
          int val = -1;
         // Obviamos comentarios del programa
          if (line.find("#") != std::string::npos) {
            line = line.substr(0, line.find("#"));
          }
          if (line.find(";") != std::string::npos) {
            line = line.substr(0, line.find(";"));
          }
          ltrim(line);
          if (line == "") {
            continue;
          }
          // Pasamos todo el texto a mayúsculas
          std::for_each(line.begin(), line.end(), [](char & c){
	          c = ::toupper(c);
          });
          // Almacenamos la etiqueta si existe
          if (line.find(":") != std::string::npos) {
            std::string tag = line.substr(0, line.find(":"));
            std::pair < std::string, int > dummy;
            dummy.first = tag;
            dummy.second = lines.size();
            tags.push_back(dummy);
            line = line.substr(line.find(":") + 1, line.size());
          }
          ltrim(line);
          if (line.find(" ") != std::string::npos) {
            std::string aux = line.substr(0, line.find(" "));
            instCode = VI.getInstCode(aux);
            line = line.substr(line.find(" "), line.size());
          } else {
            instCode = VI.getInstCode(line);
          }
          if (instCode == "") {
            std::cerr<< "No hay ningún código de instrucción que coincida con la";
            std::cerr << " línea " << lines.size() << ".\n";
            throw "Error";
          }
 
        // Extracción de información de las líneas.
        // Caso HALT
          if (instCode == VI.getInstCode("HALT")) {
            opt = 3; //Opción HALT
          } else if (line.find("=") != std::string::npos) {
         // Caso inmediato, controlando que store no reciba un inmediato
            if (instCode == VI.getInstCode("STORE")) {
              std::cerr << "Error: no se puede direccionar de manera inmediata";
              std::cerr << "con un store. Fallo en la línea " << lines.size() << ".\n";
              throw "Error";
            }
            arg = line.substr(1, line.length());
            opt = 0; //Opción de inmediatos

           // Caso de direccionamiento indirecto.
          } else if (line.find("*") != std::string::npos) {
            arg = line.substr(1, line.length());
            opt = 2; //Opción direccionamiento indirecto.

           // Caso de funciones que no reciben parámetros.
          } else if (instCode == VI.getInstCode("JGTZ") || instCode == VI.getInstCode("JZERO") ||
            instCode == VI.getInstCode("JUMP")) {
            opt = 4; //Opción sin parámetros.

        // Caso de direccionamiento directo.
          } else {
            arg = line.substr(1, line.size());
            opt = 1; //opción direccionamiento directo.
          }
          std::tuple<int, int, int> auxTuple = std::make_tuple(atoi(instCode.c_str()), opt, atoi(arg.c_str()));
          lines.push_back(auxTuple);
        }
        inFile.close();
      }


ProgramMemory::~ProgramMemory() {}

std::string ProgramMemory::typeOfInstruction(int opt) {
  switch (opt) {
    case -1:
      return "Línea vacía";
    case 0:
      return "D. INMEDIATO";
    case 1:
      return "D. DIRECTO";
    case 2:
      return "D. INDIRECTO";
    case 3:
      return "NO PARAM.";
    case 4:
      return "SALTO";
    default:
      return "TIPO NO IDENTIFICADO";
  }
}

std::tuple <int, int, int> ProgramMemory::getLine(const int &index) {
  return lines[index];
}

void ProgramMemory::setLine(const int &index,  std::tuple <int, int, int>  &value) {
  lines[index] = value;
}

std::vector < std::tuple <int, int, int> > ProgramMemory::getAllProgram() {
  return lines;
}

int ProgramMemory::numbOfLines(void) {
  return lines.size();
}


void ProgramMemory::writeProgram() {
  std::cout << "INSTRUCCIÓN\t   T. DIRECC. \t   PARÁMETRO" << std::endl;
  for (int i = 0; i < lines.size(); i++) {
    // Pasamos el código de la instrucción a cadena y traducimos el nombre con la función de ValidInstructions getInstName
    if (std::get<0>(lines[i]) != -1) {
    std::cout << "    " << VI.getInstName(std::to_string(std::get<0>(lines[i]))) << " \t | " << typeOfInstruction(std::get<1>(lines[i])) <<
     "\t | \t" << std::get<2>(lines[i]) << "\n";
    }
  }

}
