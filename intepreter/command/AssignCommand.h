#ifndef ASSIGN_COMMAND_H
#define ASSIGN_COMMAND_H

#include "Command.h"
#include "../expr/Expr.h"
#include "../expr/Variable.h"

class AssignCommand:public Command{

public:
  AssignCommand(int line, Variable* left, Expr* right);

  virtual ~AssignCommand();

  virtual void Execute();

private:
  Variable* left;
  Expr* right;
};

#endif