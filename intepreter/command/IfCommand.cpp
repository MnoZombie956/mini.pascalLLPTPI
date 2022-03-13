#include "IfCommand.h"

IfCommand::IfCommand(int line, BoolExpr *cond, Command *thenCommands)
    : Command(line), cond(cond), thenCommands(thenCommands), _elseCommands(NULL){
    };

IfCommand::~IfCommand(){
  delete cond;
  delete thenCommands;
  delete _elseCommands;
}

void IfCommand::setElseCommands(Command* elseCommands){
  _elseCommands = elseCommands;
};

void IfCommand::Execute(){
  if(cond->expr()){
    thenCommands->Execute();
  }
  else if(_elseCommands!=NULL){
    _elseCommands->Execute();
  }
}