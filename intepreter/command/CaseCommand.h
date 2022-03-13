#ifndef CASE_COMMAND_H
#define CASE_COMMAND_H

#include <list>
#include <iostream>
#include "Command.h"
#include "../expr/Expr.h"
#include "../value/Type.h"
#include "../value/IntegerValue.h"

class CaseCommand : public Command
{

public:

  CaseCommand(int line, Expr *expr);

  virtual ~CaseCommand();

  virtual void addOption(Type* value, Command* cmd);

  virtual void setOtherwise(Command* cmd);

  virtual void Execute();

private :

  class CaseOption
  {
  public:
    CaseOption(Type *value, Command *cmd) : value(value), cmd(cmd){};
    Type *value;
    Command *cmd;
  };

  Expr *expr;
  std::list<CaseOption *> options;
  Command *otherwise;
};

#endif