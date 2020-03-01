#include "../include/ProgramMemory.hpp"

//Funciones auxiliares
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
   VI("instrucciones.txt"), actualLine(0) {

    // Primero buscamos las etiquetas del programa
    findTags(file);
    // Construimos la memoria del programa
    buildProgram(file);
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

void ProgramMemory::findTags(const std::string &file) {
  std::ifstream inFile;
  inFile.open(file);
  if (!inFile) {
    std::cout << "Unable to open file";
    exit(1); // terminate with error
  }
  std::string line;
  int lineNumber = 0;

  while (getline(inFile, line)) {
    // Obviamos comentarios del programa
    if (line.find("#") != std::string::npos) {
      line = line.substr(0, line.find("#"));
    }
    if (line.find(";") != std::string::npos) {
      line = line.substr(0, line.find(";"));
    }
    ltrim(line);
    //Filtramos líneas vacías.
    if (line == "") {
      continue;
    }
    // Pasamos todo el texto a mayúsculas
    std::for_each(line.begin(), line.end(), [](char & c){
      c = ::toupper(c);
    });
    if (line.find(":") != std::string::npos) {      
      std::string tag = line.substr(0, line.find(":"));
      std::pair < std::string, int > dummy;
      dummy.first = tag;
      dummy.second = lineNumber;
      tags.push_back(dummy);
    }
    lineNumber++;
  }    
  inFile.close();            
}

void ProgramMemory::buildProgram(const std::string &file) {
  std::ifstream inFile;
  inFile.open(file);
  if (!inFile) {
    std::cout << "Unable to open file";
    exit(1); // terminate with error
  }
  std::string line;


  while (getline(inFile, line)) {
    actualLine++;
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
      std::cerr << "No hay ningún código de instrucción que coincida con la inst. de la";
      std::cerr << " línea " << actualLine << ".\n";
      throw "Error";
    }

    ltrim(line);
    // Extracción de información de las líneas.
    // Caso HALT
    if (instCode == VI.getInstCode("HALT")) {
      opt = 3; //Opción HALT
    } else if (line.find("=") != std::string::npos) {
      // Caso inmediato, controlando que store no reciba un inmediato
      if (instCode == VI.getInstCode("STORE")) {
        std::cerr << "Error: no se puede direccionar de manera inmediata ";
        std::cerr << "con una instrucción store. Fallo en la línea " << actualLine << ".\n";
        throw "Error";
      }
      arg = line.substr(1, line.length());
      opt = 0; //Opción de inmediatos

      // Caso de direccionamiento indirecto.
    } else if (line.find("*") != std::string::npos) {
      arg = line.substr(1, line.length());
      opt = 2; //Opción direccionamiento indirecto.

      // Caso de funciones de salto.
    } else if (instCode == VI.getInstCode("JGTZ") || instCode == VI.getInstCode("JZERO") ||
      instCode == VI.getInstCode("JUMP")) {
      arg = line.substr(0, line.length());
      opt = 4; //Opción de salto.

      // Caso de direccionamiento directo.
    } else {
      arg = line.substr(0, line.size());
      opt = 1; //opción direccionamiento directo.
    }
    
    // Si la instrucción es de salto hacemos la conversión de la etiqueta a entero como argumento, si no
    // almacenamos el argumento normalmente.
    if (instCode == VI.getInstCode("JGTZ") || instCode == VI.getInstCode("JZERO") ||
      instCode == VI.getInstCode("JUMP")){
        std::tuple<int, int, int> auxTuple = std::make_tuple(atoi(instCode.c_str()), opt, lineOfTag(arg));
        lines.push_back(auxTuple);
      } else {
        std::tuple<int, int, int> auxTuple = std::make_tuple(atoi(instCode.c_str()), opt, atoi(arg.c_str()));
        lines.push_back(auxTuple);
      }
  }
  inFile.close();

}

// Retorna la línea del programa en la que se encuentra la etiqueta
int ProgramMemory::lineOfTag(std::string tagName) {
  for (int i = 0; i < tags.size(); i++) {
    if (tags[i].first == tagName) {
      return tags[i].second;
    }
  }
  return -1;
}

// Retorna el nombre de la etiqueta que se encuentra en la línea dada
std::string ProgramMemory::nameOfTag(int tagLine) {
  for (int i = 0; i < tags.size(); i++) {
    if (tags[i].second == tagLine) {
      return tags[i].first;
    }
  }
  std::cerr << "Error: Se está intentando saltar a una etiqueta no definida en la línea " << tagLine;
  throw  "Error";
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
  std::cout << "LÍNEA\t   INSTRUCCIÓN\t   T. DIRECC. \t   PARÁMETRO" << std::endl;
  for (int i = 0; i < lines.size(); i++) {
    // Pasamos el código de la instrucción a cadena y traducimos el nombre con la función de ValidInstructions getInstName
    if (std::get<0>(lines[i]) != -1) {
      // Si la instrucción es de tipo SALTO mostramos la etiqueta, si es de tipo HALT no mostramos parámetro, y en otro caso mostramos el valor numérico.
      if (typeOfInstruction(std::get<1>(lines[i])) == "NO PARAM.") {
        std::cout << " " << i << "\t | " << VI.getInstName(std::to_string(std::get<0>(lines[i]))) << "   \t | " << typeOfInstruction(std::get<1>(lines[i])) <<
        "\t | \t\n";
      } else if (typeOfInstruction(std::get<1>(lines[i])) != "SALTO") {
        std::cout << " " << i << "\t | "<< VI.getInstName(std::to_string(std::get<0>(lines[i]))) << "   \t | " << typeOfInstruction(std::get<1>(lines[i])) <<
        "\t | \t" << std::get<2>(lines[i]) << "\n";
      } else {
        std::cout << " " << i << "\t | " << VI.getInstName(std::to_string(std::get<0>(lines[i]))) << "   \t | " << typeOfInstruction(std::get<1>(lines[i])) <<
        "\t | \t" << nameOfTag(std::get<2>(lines[i])) << "\n";
      }
    }
  }
}

bool ProgramMemory::taggedLine(int numberLine) {
  for (int i = 0; i < tags.size(); i++) {
    if (tags[i].second == numberLine) {
      return true;
    }
  }
  return false;
}

void ProgramMemory::disassemble() {
    for (int i = 0; i < lines.size(); i++) {
    // Comprobamos si la línea tiene etiqueta
    if (taggedLine(i)) {
      std::cout << nameOfTag(i) << ": ";
    }
    // Pasamos el código de la instrucción a cadena y traducimos el nombre con la función de ValidInstructions getInstName
    if (std::get<0>(lines[i]) != -1) {
      // Si la instrucción es de tipo SALTO mostramos la etiqueta, si es de tipo HALT no mostramos parámetro, y en otro caso mostramos el valor numérico.
      if (typeOfInstruction(std::get<1>(lines[i])) == "NO PARAM.") {
        std::cout << VI.getInstName(std::to_string(std::get<0>(lines[i]))) << "\n";
      } else if (typeOfInstruction(std::get<1>(lines[i])) != "SALTO") {
        std::cout << VI.getInstName(std::to_string(std::get<0>(lines[i]))) << " ";
        if (std::get<1>(lines[i]) == 0) {
          std::cout << "=";
        } else if (std::get<1>(lines[i]) == 2) {
          std::cout << "*";
        } 
        std::cout << std::get<2>(lines[i]) << "\n";
      } else {
        std::cout << VI.getInstName(std::to_string(std::get<0>(lines[i]))) << " " <<  nameOfTag(std::get<2>(lines[i])) << "\n";
      }
    }
  }
}

ValidInstructions ProgramMemory::getVI() {
  return VI;
}