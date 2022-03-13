#include "CompositeBoolExpr.h"
#include <iostream>

CompositeBoolExpr::CompositeBoolExpr(int line, BoolExpr *left, enum CompositeBoolExpr::BoolOp op, BoolExpr *right)
    : BoolExpr(line), left(left), op(op), right(right){};

CompositeBoolExpr::~CompositeBoolExpr(){
  delete left;
  delete right;
}

bool CompositeBoolExpr::expr(){
  switch (op)
  {
  case CompositeBoolExpr::And:
    return (left->expr() and right->expr());
    break;
  case CompositeBoolExpr::Or:
    return (left->expr() or right->expr());
    break;  
  default:
    return NULL;
    break;
  }
}