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
};

class ReadTape : public Tape {
  public:
    ReadTape(std::string &file);
    int read();
    void load(std::string &file);
};

class WriteTape : public Tape {
  public:
    void write(const int &number);
    int elementsWritten();
};
