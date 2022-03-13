#include "ReadCommand.h"

ReadCommand::ReadCommand(int line):Command(line){};

ReadCommand::~ReadCommand(){
}

void ReadCommand::addVariable(Variable* var){
  vars.push_back(var);
}

void ReadCommand::Execute(){
  for (std::list<Variable*>::iterator it = vars.begin(), end = vars.end(); it != end; it++){
    Variable* var = *it;
    if(var->expr()->type()==Type::RealType){
      float value;
      std::cin >> value;
      RealValue* rv = new RealValue(value);
      var->setValue(rv);
    }
    else if(var->expr()->type()==Type::StringType){
      std::string value;
      std::cin >> value;
      StringValue* sv = new StringValue(value);
      var->setValue(sv);
    }else{
      int value;
      std::cin >> value;
      IntegerValue* iv = new IntegerValue(value);
      var->setValue(iv);
    }

  }
}