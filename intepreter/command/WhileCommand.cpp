#include "WhileCommand.h"

WhileCommand::WhileCommand(int line, BoolExpr* cond, Command* cmds)
:Command(line), cond(cond), cmds(cmds){}

WhileCommand::~WhileCommand(){
  delete cond;
  delete cmds;
}

void WhileCommand::Execute(){
  while(cond->expr())
    cmds->Execute();
}