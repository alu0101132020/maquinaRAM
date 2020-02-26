
class Instruction {
  public:
    Instruction();
    ~Instruction();
    virtual void execute() = 0;
};

