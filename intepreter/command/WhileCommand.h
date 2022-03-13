#ifndef WHILE_COMMAND_H
#define WHILE_COMMAND_H

#include "Command.h"
#include "../expr/BoolExpr.h"

class WhileCommand:public Command{

public:
  WhileCommand(int line, BoolExpr* cond, Command* cmds);

  virtual ~WhileCommand();

  virtual void Execute();


private:
  BoolExpr* cond;
  Command* cmds;

};

#endif