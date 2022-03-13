#include "ForCommand.h"

ForCommand::ForCommand(int line, Variable* var, Expr* src, Expr* dst, Command* cmd)
:Command(line), var(var), src(src), dst(dst), cmd(cmd){}

ForCommand::~ForCommand(){
  delete var;
  delete src;
  delete dst;
  delete cmd;
}

void ForCommand::Execute(){
  var->setValue(src->expr());
  int i = ((IntegerValue*)src->expr())->value();
  int j = ((IntegerValue*)dst->expr())->value();
  while(i<j){
    cmd->Execute();
    i++;
    var->setValue(new IntegerValue(i));
  }
}