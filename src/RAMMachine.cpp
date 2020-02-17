

class RAMMachine {
  private:
    Registers registerMemory;
    ProgramMemory programMemory;
    WriteTape writeTape;
    ReadTape readTape;
    //Instruction *Instruction;
    int programCounter;

  public:
    RAMMachine();
    void writeState();
}
