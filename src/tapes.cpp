#include "../include/tapes.hpp"

Tape::Tape()
    : head(-1) {}


Tape::~Tape() {}

void Tape::moveForward(void) {
  head++;
}

void Tape::showTape(void) {
  for (int i = 0; i < elements.size(); i++) {
    std::cout << "| " << elements[i] << " | ";
  }
  std::cout << "\n";
}

ReadTape::ReadTape(std::string& file) {
  load(file);
}

int ReadTape::read() {
  moveForward();
  return elements[head];
}

void ReadTape::load(std::string& file) {
  std::ifstream inFile;
  inFile.open(file);
  if (inFile.is_open()) {
    while (inFile) {
      int readElement;
      inFile >> readElement;
      elements.push_back(readElement);
    }
  } else {
    std::cout << "Unable to open file";
    exit(1); // terminate with error
  }
  inFile.close(); 
}

WriteTape::WriteTape(std::string &file) :
 outputFile(file) {}

void WriteTape::writeOnFile() {
  std::ofstream outFile;
  outFile.open(outputFile);
  if (outFile.is_open()) {
    for (int i = 0; i < elements.size(); i++) {
      outFile << elements[i];
    }
  } else {
    std::cout << "Unable to open file";
    exit(1); // terminate with error
  }
  outFile.close(); 
}

Tape Tape::getTape(void) {
  return *this;
}


int WriteTape::elementsWritten(void) {
	return elements.size();
}

void WriteTape::write(const int &number) {
  moveForward();
  elements.resize(elements.size() + 1);
  elements[head] = number;
}
