#include "AssignCommand.h"

AssignCommand::AssignCommand(int line, Variable *left, Expr *right)
    : Command(line), left(left), right(right){};

AssignCommand::~AssignCommand(){
  delete left;
  delete right;
}

void AssignCommand::Execute(){
  left->setValue(right->expr());
}