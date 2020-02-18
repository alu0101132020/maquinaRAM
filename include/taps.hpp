#include <vector>
#include <fstream>

class Tape {
  protected:
    std::vector<int> elements;
    int head;

  public:
    Tape();
    ~Tape();
  private:
    void moveForward();
};

class ReadTape : public Tape {
  public:
    ReadTape( std::string &file);
    void read(const int &number);
    void load(std::string &file);
  private:

};


class WriteTape : public Tape {
  public:
    void write(const int &number);
    int elementsWritten();
};
