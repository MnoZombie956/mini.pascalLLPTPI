#include "SingleBoolExpr.h"

SingleBoolExpr::SingleBoolExpr(int line, Expr* left, enum SingleBoolExpr::Op RelOp, Expr* right)
  : BoolExpr(line), left(left), RelOp(RelOp), right(right){}

SingleBoolExpr::~SingleBoolExpr(){
  delete left;
  delete right;
}

bool SingleBoolExpr::expr(){
  Type* t1 = left->expr();
  Type* t2 = right->expr();

  float v1=0, v2=0;

  if(t1->type()==Type::IntegerType)
    v1 = ((IntegerValue*) t1)->value(); 
  else if(t1->type()==Type::RealType)
    v1 = ((RealValue*) t1)->value();
  if(t2->type()==Type::IntegerType)
    v2 = ((IntegerValue*) t2)->value(); 
  else if(t2->type()==Type::RealType)
    v2 = ((RealValue*) t2)->value();


  switch (RelOp)
  {
  case SingleBoolExpr::EQUAL:
    return v1 == v2;
    break;
  case SingleBoolExpr::NOT_EQUAL:  
    return v1 != v2;
    break;
  case SingleBoolExpr::LOWER_THAN:
    return v1 < v2;
    break;
  case SingleBoolExpr::LOWER_EQUAL:
    return v1 <= v2;
    break;
  case SingleBoolExpr::GREATER_THAN:
    return v1 > v2;
    break;
  case SingleBoolExpr::GREATER_EQUAL:
    return v1 >= v2;
    break;
  default:
    return NULL;
    break;
  }
}