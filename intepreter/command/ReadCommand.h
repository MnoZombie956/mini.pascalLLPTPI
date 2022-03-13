#ifndef READ_COMMAND_H
#define READ_COMMAND_H

#include <list>
#include <iostream>
#include "Command.h"
#include "../expr/Variable.h"
#include "../value/IntegerValue.h"
#include "../value/RealValue.h"
#include "../value/StringValue.h"

class ReadCommand:public Command{

public:
  ReadCommand(int line);

  virtual ~ReadCommand();

  virtual void addVariable(Variable* var);

  virtual void Execute();

private:
  std::list<Variable*> vars;

};



#endif