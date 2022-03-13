#ifndef IF_COMMAND_H
#define IF_COMMAND_H

#include <iostream>
#include "Command.h"
#include "../expr/BoolExpr.h"
#include "../command/Command.h"

class IfCommand: public Command{

public:

  IfCommand(int line, BoolExpr* cond, Command* thenCommands);

  virtual ~IfCommand();

  virtual void setElseCommands(Command* elseCommands);

  virtual void Execute();

private:
  BoolExpr* cond;
  Command* thenCommands;
  Command* _elseCommands;

};

#endif