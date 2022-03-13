#include "CaseCommand.h"

CaseCommand::CaseCommand(int line, Expr* expr):Command(line), expr(expr), otherwise(NULL){
};

CaseCommand::~CaseCommand(){
  delete expr;
  delete otherwise;
}

void CaseCommand::addOption(Type* value, Command* cmd){
  options.push_back(new CaseOption(value, cmd));
}

void CaseCommand::setOtherwise(Command* cmd){
  otherwise = cmd;
}

void CaseCommand::Execute(){
  bool executou = false;
  for (std::list<CaseOption*>::iterator it = options.begin(), end = options.end(); it != end and executou==false; it++){
    CaseOption* c = *it;
    // std::cout<<expr->expr()<< " " << c->value << std::endl; 
    if(((IntegerValue*)expr->expr())->value()==((IntegerValue*)c->value)->value()){
      executou = true;
      c->cmd->Execute();
    }
  }
  if(not executou and otherwise!=NULL){
    otherwise->Execute();
  }
}