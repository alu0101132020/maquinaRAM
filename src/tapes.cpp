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
  if (inFile.is_open()) {
      while (inFile) {
        int readElement;
        inFile >> readElement;
        elements.push_back(readElement);
      }
      inFile.close();
  }
}

int WriteTape::elementsWritten(void) {
	return Tape::elements.size();
}

void WriteTape::write(const int &number) {
  moveForward();
  elements[head] = number;
}
