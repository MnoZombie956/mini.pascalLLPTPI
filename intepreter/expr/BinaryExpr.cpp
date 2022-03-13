#include "BinaryExpr.h"

BinaryExpr::BinaryExpr(int line, Expr *left, enum BinaryExpr::BinaryOp op, Expr *right)
    : Expr(line), left(left), op(op), right(right) {}

BinaryExpr::~BinaryExpr(){
  delete left;  
  delete right;
};

Type* BinaryExpr::expr(){
  Type* t1 = left->expr();
  Type* t2 = right->expr();

  int v1 = ((IntegerValue*) t1)->value();
  int v2 = ((IntegerValue*) t2)->value();

  switch (op)
  {
  case BinaryOp::AddOp:
    return new IntegerValue(v1+v2);
    break;
  case BinaryOp::SubOp:
    return new IntegerValue(v1-v2);
    break;
  case BinaryOp::MulOp:
    return new IntegerValue(v1*v2);
    break;
  case BinaryOp::DivOp:
    return new IntegerValue(v1/v2);
    break;
  case BinaryOp::ModOp:
    return new IntegerValue(v1%v2);
    break;
  default:
    return NULL;
    break;
  }

}